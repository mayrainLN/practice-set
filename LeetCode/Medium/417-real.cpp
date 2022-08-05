#include"bits/stdc++.h"
using namespace std;
class Solution {
 public:
  vector<vector<int>> ans;
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    //记录太平洋是否能回流到  两个vector初始化的嵌套
    vector<vector<int>> pa = vector<vector<int>>(m, vector<int>(n, 0));
    vector<vector<int>> at = vector<vector<int>>(m, vector<int>(n, 0));

    for (int i = 0; i < heights.size(); i++) {     //搜索左右两边界
      dfs(heights, pa, i, 0);                      //遍历左边 太平洋
      dfs(heights, at, i, heights[0].size() - 1);  //遍历右边 大西洋
    }

    for (int j = 0; j < heights[0].size(); j++) {  //搜索上下两边界
      dfs(heights, pa, 0, j);                      //遍历上边 太平洋
      dfs(heights, at, heights.size() - 1, j);     //遍历右边 大西洋
    }

    for (int i = 0; i < heights.size(); i++) {
      for (int j = 0; j < heights[0].size(); j++) {
        if (pa[i][j] != 0 && at[i][j] != 0) {
          vector<int> v;
          v.push_back(i);
          v.push_back(j);
          ans.push_back(v);
        }
      }
    }
    return ans;
  }

  void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int i,int j) {
    if (visited[i][j] != 0) {
      return;
    }
    //没有越界
    visited[i][j]++;
    //继续回流到更高点
    int tem = heights[i][j];
		//深度搜索
    if (i + 1 < heights.size() && heights[i + 1][j] >= tem) {
      dfs(heights, visited, i + 1, j);
    }

    if (i - 1 >= 0 && heights[i - 1][j] >= tem) {
      dfs(heights, visited, i - 1, j);
    }

    if (j + 1 < heights[0].size() && heights[i][j + 1] >= tem) {
      dfs(heights, visited, i, j + 1);
    }

    if (j - 1 >= 0 && heights[i][j - 1] >= tem) {
      dfs(heights, visited, i, j - 1);
    }
  }
};