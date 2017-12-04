#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    void rotate(vector<vector<int>>& matrix){
        reverse(matrix.begin(), matrix.end());
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix.size();j++){
                if(i!=j)
                    swap(matrix[i][j], matrix[j][i]);
            }
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
    cout << "Hello World!" << endl;
    return 0;
}
