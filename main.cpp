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
    //78. Subsets 2017-12-25 15:30-16:13
    //Two solutions, bit-manipulation or recursive the fowllowing is recursive way
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
        //the most important thing is to push it in the first of the recursive function
        v_sets.push_back(temp_list);

        for(int i=start;i<nums.size();i++){
            if(i>start && nums[i]==nums[i-1]) continue;
            temp_list.push_back(nums[i]);
            backtrack(v_sets, temp_list, nums, i+1);
            temp_list.pop_back();
        }
    }

    //46. Permutations
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> vec_list;
        backtrack_p(results, vec_list, nums);
        return results;
    }
    void backtrack_p(vector<vector<int>> &vec, vector<int>& vec_list, vector<int>& nums){
        if(vec_list.size()==nums.size())
            vec.push_back(vec_list);
<<<<<<< HEAD
        else{
            for(int i=0;i<nums.size();i++){
                if(find(vec_list.begin(), vec_list.end(), nums[i])==vec_list.end())
                {
                    vec_list.push_back(nums[i]);
                    backtrack_p(vec, vec_list, nums);
                    vec_list.pop_back();
                }
            }
        }
    }
    //47. Permutations II
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> vec_list;
        vector<bool> used(nums.size(), false);
        backtrack_p2(results, vec_list, nums, used);
        return results;
    }
    void backtrack_p2(vector<vector<int>> &vec, vector<int>& vec_list, vector<int>& nums, vector<bool>& used){
        if(vec_list.size()==nums.size()){
            vec.push_back(vec_list);
        }
        for(int i=0;i<nums.size();i++){
            if(used[i] || i>0 && nums[i]==nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            vec_list.push_back(nums[i]);
            backtrack_p2(vec, vec_list, nums, used);
            used[i] = false;
            vec_list.pop_back();
=======
        for(int i=0;i<nums.size();i++){
            if(find(vec_list.begin(), vec_list.end(), nums[i])==vec_list.end())
            {
                vec_list.push_back(nums[i]);
                backtrack_p(vec, vec_list, nums);
                vec_list.pop_back();
            }
>>>>>>> fc6c4674cf788487c8508a3ecda6464163786783
        }
    }
};

int main(int argc, char *argv[])
{
    Solution solution;
<<<<<<< HEAD
//    vector<vector<int>> a = {{1,2,3},{4,5,6},{7,8,9}};
//    solution.rotate(a);
//    for(auto ele:a){
//        for(auto e:ele){
//            cout << e;
//        }
//        cout << endl;
//    }
//    cout << "solution start" << endl;
    vector<int> nums = {1,1,2};
    vector<vector<int>> b;
    b=solution.permuteUnique(nums);
=======
    solution.rotate(a);
    for(auto ele:a){
        for(auto e:ele){
            cout << e;
        }
        cout << endl;
    }
    cout << "solution start" << endl;
    vector<int> nums = {1,2,3};
    vector<vector<int>> b;
    b=solution.permute(nums);
>>>>>>> fc6c4674cf788487c8508a3ecda6464163786783
    for(auto ele:b){
        for(auto e:ele){
            cout << e;
        }
        cout << endl;
    }
    cout << "Hello World!" << endl;
    return 0;
 }
