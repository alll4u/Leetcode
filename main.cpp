/*********************************************************
 *  @brief: : Leetcode practice
 *  @author : Jeffrey Yin
 *  @github : alll4u
 *  @date   : 2017-12-06
**********************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <test.h>
#include <math.h>
#include <time.h>

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
        }
    }
    //39. Combination Sum
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> vec_list;
        backtrack_c(results, vec_list, candidates, 0, target);
        return results;
    }
    void backtrack_c(vector<vector<int>>& vec, vector<int>& vec_list, vector<int>& nums, int start, int target){
        if(target<0)
            return;
        else if(target==0){
            vec.push_back(vec_list);
        }
        else{
            for(int i=start;i<nums.size();i++){
                vec_list.push_back(nums[i]);
                backtrack_c(vec, vec_list, nums, i, target-nums[i]);
                vec_list.pop_back();
            }
        }
    }
    //40. Combination Sum II
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> results;
        vector<int> vec_list;
        backtrack_c2(results, vec_list, candidates, 0, target);
        return results;
    }
    void backtrack_c2(vector<vector<int>>& vec, vector<int>& vec_list, vector<int>& nums, int start, int target){
        if(target<0)
            return;
        else if(target==0){
            vec.push_back(vec_list);
        }
        else{
            for(int i=start;i<nums.size();i++){
                if(i>start && nums[i]==nums[i-1]) continue;
                vec_list.push_back(nums[i]);
                backtrack_c2(vec, vec_list, nums, i+1, target-nums[i]);
                vec_list.pop_back();
            }
        }
    }
    //131. Palindrome Partitioning
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> temp;
        backtrack_pli(results, s, temp, 0);
        return results;

    }
    void backtrack_pli(vector<vector<string>>& vec, string& s, vector<string> temp, int start){
        if(start==s.size())
            vec.push_back(temp);
        for(int i=start;i<s.size();i++){
            if(is_plindrome_substr(s, start, i)){
                temp.push_back(s.substr(start, i-start+1));
                backtrack_pli(vec, s, temp, i+1);
                temp.pop_back();
            }
        }


    };
    bool is_plindrome(string s){
        bool is_ = true;

        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i])
                is_ = false;
        }
        return is_;
    }
    bool is_plindrome_substr(string s, int start, int end){
        while(start<= end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    /*********************************************************
     *  @function : find all substring in string s
     *  @brief    : ind all substring in string s
     *  @input    : string
     *  @output   : vector<string>
    **********************************************************/
    vector<string> substring(string s){
        vector<string> results;
        set<string> myset;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(is_plindrome(s.substr(i, j-i+1)))
                    myset.insert(s.substr(i, j-i+1));
            }
        }
        for(auto ele:myset)
            results.push_back(ele);
        return results;
    }
    /*********************************************************
     *  @function : groupAnagrams
     *  @brief    : string problems
     *  @input    : yep
     *  @output   : yep
    **********************************************************/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m_results;
        vector<vector<string>> results;
        for(auto str : strs){
            vector<char> copy_str(str.size());
            string temp_str;
            copy(str.begin(), str.end(), copy_str.begin());
            sort(copy_str.begin(), copy_str.end());
            temp_str.assign(copy_str.begin(), copy_str.end());
            if(!m_results.count(temp_str))
                m_results.insert(make_pair(temp_str, vector<string> ()));
            m_results[temp_str].push_back(str);
            cout << temp_str << endl;
        }
        for(auto vec : m_results){
            results.push_back(vec.second);
        }
        return results;
    }
    /*********************************************************
     *  @no       : 55
     *  @function : canJump
     *  @brief    : whether can jump to the end of the vector
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach=0;
        int i=0;
        for(i=0;i<n && i<=reach;i++){
            reach=max(reach, nums[i]+i);
        }
        return i==n;
    }
    /*********************************************************
     *  @no       : 56
     *  @function : Merge Intervals
     *  @brief    : desription
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
    };
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty())
            return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start<b.start;});
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(res.back().end<intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end = max(intervals[i].end, res.back().end);

        }
        return res;
    }
    /*********************************************************
     *  @no       : 57
     *  @function : insert intervals
     *  @brief    : desription
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start<b.start;});
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(res.back().end<intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end = max(intervals[i].end, res.back().end);

        }
        return res;
    }
    /*********************************************************
     *  @no       : 74
     *  @function : search a 2D matrix
     *  @brief    : desription
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        if(matrix[0].empty())
            return false;
        const int m = matrix.size();

        const int n = matrix[0].size();

        int m_left = 0;
        int m_right = m-1;
        int m_mid;
        while(m_left <= m_right){
            m_mid = (m_left + m_right) / 2;
            if(m_left == m_right && !(matrix[m_mid][0] <=target && target <= matrix[m_mid][n-1])){
                return false;
            }
            if(matrix[m_mid][0] <=target && target <= matrix[m_mid][n-1]){
                //to find in mid
                int n_left = 0;
                int n_right = n-1;
                int n_mid;
                while(n_left <= n_right){
                    n_mid = (n_left + n_right) / 2;
                    if(n_left==n_right && target != matrix[m_mid][n_mid])
                        return false;
                    if(target == matrix[m_mid][n_mid]){
                        return true;
                    }
                    else if(target < matrix[m_mid][n_mid]){
                        n_right = n_mid-1;
                    }
                    else if(target > matrix[m_mid][n_mid]){
                        n_left = n_mid+1;
                    }
                }
            }
            else if(target < matrix[m_mid][0]){
                //update mid in left
                m_right = m_mid-1;
            }
            else if(target > matrix[m_mid][n-1]){
                //update mid in right
                m_left = m_mid+1;
            }
            return false;
        }
    }
    /*********************************************************
     *  @no       : xx
     *  @time     : 12.20
     *  @function : 水仙花数
     *  @brief    : desription
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    vector<int> shuixianhua(int n){
        vector<int> results;
        for(int i=1,temp,remainder,sum=0;i<n;i++){
            sum=0;
            remainder=i%10;
            sum+=remainder*remainder*remainder;
            temp/=10;
            while(temp>0){
                remainder=temp%10;
                sum+=remainder*remainder*remainder;
                temp/=10;
            }
            if(sum==i)
                results.push_back(i);
        }
        for(auto e:results)
            cout << e << " "<<endl;
        return results;
    }
    /*********************************************************
     *  @no       : 59
     *  @time     : 12.20
     *  @function : spiral matrix
     *  @brief    : desription
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> results(n,vector<int>(n,3));
        int x=1;
        for(int i=0;i<ceil(n/2.0);i++){
            for(int j=i;j<n-i;j++)
                results[i][j]=x++;
            for(int j=i+1;j<n-i;j++)
                results[j][n-1-i]=x++;
            for(int j=n-2-i;j>=i;j--)
                results[n-1-i][j]=x++;
            for(int j=n-2-i;j>i;j--)
                results[j][i]=x++;
        }
        for(auto e:results){
            for(auto f:e){
                cout << f << " ";
            }
            cout << endl;
        }


        return results;
    }
    /*********************************************************
     *  @no       : 575
     *  @time     : 12-21
     *  @function : Distrbute candies
     *  @brief    : desription
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
//    int distributeCandies(vector<int>& candies) {
//        candies.sort(candies.begin(), candies.end());
//        map<int, int> candy;
//        int amount;
//        for(auto e: candies){
//            iamount++;
//            map[e]++;
//        }

//    }
    /*********************************************************
     *  @no       : 575
     *  @time     : 2017-12-22
     *  @function : Distribute Candies
     *  @brief    : An EZ Problem; BORING!!
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    int distributeCandies(vector<int>& candies) {
        // sort(candies.begin(), candies.end());
        set<int> candy;
        for(auto e:candies){
            candy.insert(e);
        }
        return candies.size()/2>candy.size() ? candy.size() : candies.size()/2;
    }
    /*********************************************************
     *  @no       : 73
     *  @time     : 12-27
     *  @function : Set Matrix Zeroes
     *  @brief    : desription
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> column;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for(auto e:row){
            for(int i=0;i<matrix.size();i++){
                if(e==i){
                    for(int j=0;j<matrix[0].size();j++)
                        matrix[i][j]=0;
                }
            }
        }
        for(auto e:column)
            for(int i=0;i<matrix.size();i++)
                for(int j=0;j<matrix[0].size();j++)
                    if(e==j)
                        matrix[i][j]=0;

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout << matrix[i][j];
            }
            cout << endl;
        }

    }
    void setZeroes2(vector<vector<int>>& matrix){
        int row = matrix.size();
        int column = matrix[0].size();
        int col0 = 1;
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0)col0=0;
            for(int j=1;j<column;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=row-1;i>=0;i--){
            for(int j=column-1;j>0;j--){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
            if(col0==0)matrix[i][0]=0;
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout << matrix[i][j];
            }
            cout << endl;
        }

    }
    /*********************************************************
     *  @no       : 79
     *  @time     : 2018-01-03
     *  @function : Word Search
     *  @brief    : desription
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    bool exist2(vector<vector<char>>& board, string word) {
        vector<vector<bool>> flag(board.size(), vector<bool>(board[0].size(), false));
        vector<vector<int>> results = find_ch(board, flag, word[0]);
        if(results.empty())
            return false;
        for(int i=1;i<word.size();i++){
            vector<vector<int>> sum;
            for(int j=0;j<results.size();j++){
                vector<vector<int>> temp = find_next(board, flag, results[j], word[i]);
                sum.insert(sum.end(), temp.begin(), temp.end());
            }
            if(!sum.empty())
                results = sum;
            else
                return false;
        }
        return true;

    }
    vector<vector<int>> find_ch(vector<vector<char>> &board, vector<vector<bool>> &flag, char target){
        vector<vector<int>> results;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==target){
                    results.push_back({i, j});
                    flag[i][j]=true;
                }
            }
        }
        return results;
    }
//    vector<vector<int>> find_ch_direct(vector<vector<char>> &board, vector<vector<bool>>& flag,char target){
//        vector<vector<int>> results;
//        for(int i=0;i<board.size();i++){
//            for(int j=0;j<board[0].size();j++){
//                if(board[i][j]==target && !flag[i][j]){
//                    flag[i][j]=true;
//                    results.push_back({i, j});
//                }
//            }
//        }
//        return results;
//    }
    vector<vector<int>> find_next(vector<vector<char>> &board,
                                  vector<vector<bool>> &flag,
                                  vector<int> current_pos,
                                  char target){
        int m = board.size();
        int n = board[0].size();
        int x=current_pos[0];
        int y=current_pos[1];
        vector<vector<int>> results;
        //向上
        x-=1;
        if(x>=0&&x<m && y>=0&&y<n){
            if(board[x][y]==target && !flag[x][y]){
                results.push_back({x, y});
                flag[x][y]=true;
            }
        }
        //向下
        x+=2;
        if(x>=0&&x<m && y>=0&&y<n){
            if(board[x][y]==target && !flag[x][y]){
                results.push_back({x, y});
                flag[x][y]=true;
            }
        }
        //向左
        x-=1;
        y-=1;
        if(x>=0&&x<m && y>=0&&y<n){
            if(board[x][y]==target && !flag[x][y]){
                results.push_back({x, y});
                flag[x][y]=true;
            }
        }
        //向右
        y+=2;
        if(x>=0&&x<m && y>=0&&y<n){
            if(board[x][y]==target && !flag[x][y]){
                results.push_back({x, y});
                flag[x][y]=true;
            }
        }
        return results;
    }
    /*********************************************************
     *  @no       : 79
     *  @time     : 2018-01-04
     *  @function : word search
     *  @brief    : desription
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> flag(m, vector<bool>(n, false));
        for(int x=0;x<m;x++)
            for(int y=0;y<n;y++){
                    if(dfs(board, flag, x, y, 0, word)){
                        cout << "true" << endl;
                        return true;
                    }

            }
        return false;
    }
    //use Recursive dfs
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& flag,
             int x, int y, int idx, string word){
        int m = board.size();
        int n = board[0].size();
        if(idx==word.size())
            return true;
        if(x<0 || x>=m || y<0 || y>=n || board[x][y]!=word[idx] || flag[x][y]!=false)
            return false;
        flag[x][y]=true;
        if(dfs(board, flag, x-1, y, idx+1, word)
                || dfs(board, flag, x, y-1, idx+1, word)
                || dfs(board, flag, x, y+1, idx+1, word)
                || dfs(board, flag, x+1, y, idx+1, word))
            return true;
        else{
            flag[x][y]=false;
            return false;
        }
    }
    /*********************************************************
     *  @no       : combination numbers
     *  @time     : time
     *  @function : name
     *  @brief    : desription
     *  @input    : in  para type
     *  @output   : out para type
    **********************************************************/
    vector<vector<int>> combinationKinds(vector<int>& candidates, int target){
        vector<vector<int>> result;
        vector<int> local;
        sort(candidates.begin(), candidates.end());
        addCombination(result, local, candidates, 0, target);
        return result;

    }
    void addCombination(vector<vector<int>> &result, vector<int> &local,
                        vector<int> &nums, int begin, int target){
        if(local.size()==target){
            result.push_back(local);
            return;
        }
        else{
            for(int i=begin; i<nums.size(); i++){
                local.push_back(nums[i]);
                addCombination(result, local, nums, i+1, target);
                local.pop_back();
            }
        }
    }

//    bool searchMatrix(vector<vector<int>>& matrix, int target) {
//        int m = matrix.size();
//        int n = matrix[0].size();
//        for(int i=0;i<m;i++)
//            for(int j=0;j<n;j++){
//                int temp = matrix[i][j];
//                if(temp==target)
//                    return true;
//            }
//        return false;
//    }
};
typedef void(*Fun)(void);
void show(){
    cout << "fuck u" << endl;
}

int main(int argc, char *argv[])
{
    Solution a;
    vector<int> b ;
    for(int i=0;i<30;i++)
        b.push_back(i);
    vector<vector<int>> results;
    int target = 14;
    clock_t cstart,cends;
    cstart = clock();
    results = a.combinationKinds(b, target);
    cends = clock();
    cout << "duration:"<<cends-cstart<<endl;
//    for(auto ele:results){
//        for(auto e:ele)
//            cout << e;
//        cout << endl;
//    }
    return 0;
 }
