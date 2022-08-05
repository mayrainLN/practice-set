#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<vector<int>> result; // 存放符合条件结果的集合
    vector<int> path; // 用来存放符合条件结果
    void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i); // 处理节点 
            backtracking(n, k, i + 1); // 递归  深度搜索，遇到目标叶子后,储存,返回上一层；
            path.pop_back(); // 返回上一层后，回溯，撤销处理的节点，复原路径;
														 //for使得在当前深度继续横向遍历 
        }
    }
    vector<vector<int>> combine(int n, int k) {
         backtracking(n, k, 1);
        return result;
    }
};