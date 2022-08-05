#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backTracking(vector<int>& nums,vector<bool>& used){
        
        //符合条件，记录结果
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            //横向遍历
            if(used[i]){//已经排序了，直接进入下一轮循环
                continue;
            }
            //在path记录所经过路径
            used[i]=true;

            path.push_back(nums[i]);
            backTracking(nums,used);
            //返回一个结果后,往上层回溯    
            path.pop_back();
            used[i]=false;
        }
        //当前深度横向已经遍历完了
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(),false);
        backTracking(nums,used);
        return res;
    }
    int asd() {}
};
int main() {
  return 0;
}