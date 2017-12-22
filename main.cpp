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
    int distributeCandies(vector<int>& candies) {
        candies.sort(candies.begin(), candies.end());
        map<int, int> candy;
        int amount;
        for(auto e: candies){
            iamount++;
            map[e]++;
        }

    }
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

;
//    a.generateMatrix(5);
//    a.generateMatrix(0);
    a.generateMatrix(3);
//    Test b;

//    Fun pFun = NULL;

//    cout << "虚函数表地址：" << (long*)(&b) << endl;
//    cout << "虚函数表 — 第一个函数地址：" << (long*)*(long*)(&b) << endl;

//    // Invoke the first virtual function
//    pFun = (Fun)*((long*)*(long*)(&b));
//    pFun();


    return 0;
 }
