#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
    //48. Rotate Image 2017-12-4 22:54
    void rotate(vector<vector<int>>& matrix){
        reverse(matrix.begin(), matrix.end());
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++){
                if(i!=j)
                    swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    //78. Subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> init;
        sort(nums.begin(), nums.end());
        backtrack(results, init, nums, 0);
        cout << "init is" << init.size() << endl;
        return results;
    }
    void backtrack(vector<vector<int>> &v_sets, vector<int> &temp_list, vector<int>& nums, int start){
        //vector<int> temp_list(t_list);

        v_sets.push_back(temp_list);

        for(int i=start;i<nums.size();i++){
            temp_list.push_back(nums[i]);
            backtrack(v_sets, temp_list, nums, i+1);
            temp_list.pop_back();
        }
    }

    //46. Permutations
    vector<vector<int>> permute(vector<int>& nums) {
         vector<vector<int>> result;
         vector<int> line;
         int cycle_times=1;
         for(int i=nums.size();i>0;i--)
             cycle_times*=i;
         for(int i=0;i<cycle_times;i++){
             line.push_back(nums[i]);
         }
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
    Solution solution;
    solution.rotate(a);
    for(auto ele:a){
        for(auto e:ele){
            cout << e;
        }
        cout << endl;
    }
    vector<int> nums = {1,2,3};
    vector<vector<int>> b;
    b=solution.subsets(nums);
    for(auto ele:b){
        for(auto e:ele){
            cout << e;
        }
        cout << endl;
    }
    cout << "Hello World!" << endl;
    return 0;
}
