#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> used;
    vector<vector<int>> ans;
    vector<int> path;
    void backTracking(vector<int>& nums,vector<bool>& used,vector<int>& path,vector<vector<int>>& ans){
        // 找到一条排序路径
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }

        // 横向遍历时，如果下一个节点在本层已经被访问了，就不用再进入深度搜索了；
        for(int i=0;i<nums.size();i++){
            //在本层中，待访问的数已经访问过或者与上个已经访问的数重复
            if(used[i]||(i > 0 && nums[i] == nums[i - 1] && !used[i - 1])){
                continue;
            }
            // 进入排序
            // 记录路径
            path.push_back(nums[i]);
            // 进入下一层，dfs
            used[i]=true;
            backTracking(nums,used,path,ans);
            // 下一层搜索完毕
            used[i]=false;
            // 回溯
            path.pop_back();
            // 在本层继续搜索
        }     
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 全部未访问
        used=vector<bool>(nums.size(),false);
        sort(nums.begin(),nums.end());
        // 开始深度搜索
        backTracking(nums,used,path,ans);
        return ans;
    }
};