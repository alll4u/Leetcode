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

};
typedef void(*Fun)(void);
void show(){
    cout << "fuck u" << endl;
}

int main(int argc, char *argv[])
{
    Solution a;
    vector<vector<string>> results;
    vector<string> test_str = {"abc","bca","add","dda","acb"};
    results = a.groupAnagrams(test_str);
//    Test b;

//    Fun pFun = NULL;

//    cout << "虚函数表地址：" << (long*)(&b) << endl;
//    cout << "虚函数表 — 第一个函数地址：" << (long*)*(long*)(&b) << endl;

//    // Invoke the first virtual function
//    pFun = (Fun)*((long*)*(long*)(&b));
//    pFun();
    vector<int> aa = {1,2,3,4};
    cout<< a.canJump(aa) << endl;

    return 0;
 }
