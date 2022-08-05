#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void dfs(vector<vector<int>>& heights, int i, int j,
           vector<vector<int>>& pflag, int type) {
    //越界
    if (i < 0 || i > heights.size() - 1 || j < 0 || j > heights[0].size() - 1) {
      return;
    }
    //标记当前位置
    // type 1太平洋搜索 2大西洋搜索
    if (type == 1) {
      ++pflag[i][j];
    } else {  //太平洋能到达，才会继续检查大西洋。这样防止大西洋出错
      if (pflag[i][j] != 0) {
        pflag[i][j] = 4;
      }
    }
    //当前位置搜索完毕
    //向四周搜索
    int tem = heights[i][j];
    if (i + 1 < heights.size()) {
      if (heights[i + 1][j] >= tem) {
        dfs(heights, i + 1, j, pflag, type);
      }
    }

    if (i - 1 >= 0) {
      if (heights[i - 1][j] >= tem) {
        dfs(heights, i - 1, j, pflag, type);
      }
    }

    if (j + 1 < heights[0].size()) {
      if (heights[i][j + 1] >= tem) {
        dfs(heights, i, j + 1, pflag, type);
      }
    }
    if (j - 1 >= 0) {
      if (heights[i][j - 1] >= tem) {
        dfs(heights, i, j - 1, pflag, type);
      }
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    //每个位置的flag标记。初始化大小和值
    vector<vector<int>> pflag(heights.size());  //指定行数
    for (auto& i : pflag) {                     //指定每行列数
      i.resize(heights[0].size());              //值默认为0
    }

    // 从最上方搜索 i=0,j=x type 1太平洋搜索
    for (int j = 0; j < heights[0].size(); j++) {
      dfs(heights, 0, j, pflag, 1);
    }
    //左
    for (int i = 0; i < heights.size(); i++) {
      dfs(heights, i, 0, pflag, 1);
    }
    // 从最右方搜索 i=x,j=height[0].size() type 2 大西洋搜索
    for (int i = 0; i < heights.size(); i++) {
      dfs(heights, i, heights[0].size() - 1, pflag, 2);
    }
    // 从最下方搜索 i=height.size(),j=x type 2 大西洋搜索
    for (int j = 0; j < heights[0].size(); j++) {
      dfs(heights, heights.size() - 1, j, pflag, 2);
    }

    //检查
    vector<vector<int>> ans;
    for (int i = 0; i < heights.size(); i++) {
      for (int j = 0; j < heights[0].size(); j++) {
        if (pflag[i][j] == 4) {
          vector<int> v;
          v.push_back(i);
          v.push_back(j);
          ans.push_back(v);
        }
      }
    }
    return ans;
  }
};
int main() {
  Solution sol;
  //   [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
  vector<vector<int>> v;
  vector<int> v1 = {1, 2, 2, 3, 5};
  vector<int> v2 = {3, 2, 3, 4, 4};
  vector<int> v3 = {2, 4, 5, 3, 1};
  vector<int> v4 = {6, 7, 1, 4, 5};
  vector<int> v5 = {5, 1, 1, 2, 4};

  v.push_back(v1);
  v.push_back(v2);
  v.push_back(v3);
  v.push_back(v4);
  v.push_back(v5);
  sol.pacificAtlantic(v);
  return 0;
}