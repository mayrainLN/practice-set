#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int level = 0; //第一次循环，level++，若直接返回,说明
  bool findIsland = false;
  int dir[5] = {-1, 0, 1, 0, -1};
  int shortestBridge(vector<vector<int>>& grid) {
    int ii, jj;
    for (int i = 0; i < grid.size(); i++) {
      if (!findIsland) {
        for (int j = 0; j < grid[0].size(); j++) {
          //找到第一个岛屿的入口
          if (grid[i][j] == 1) {
            //记录岛屿起始位置
            ii = i;
            jj = j;
            findIsland = true;
            break;
          }
        }
      }
    }
    queue<pair<int, int>> points;
    dfs(grid, ii, jj,points);
    //大岛屿置为2；

    // 从大岛屿往外，一层将海水置为2，直到遇到1
 
    while (!points.empty()) {
      //每一次while循环都是向内一层拓展
     
      int levelPointNum=points.size();
      //遍历大岛当前最内层
      while (levelPointNum--) {
        pair<int, int> tem = points.front();
        points.pop();
        int i = tem.first, j = tem.second;

        //等于1->返回level 等于2->不管 等于0->入队
        for (int k = 0; k < 4; k++) {
            int y=i+dir[k],x=j+dir[k+1];
            if(y<0||y>=grid.size()||x<0||x>=grid[0].size()){
                continue;
            }
            if(grid[y][x]==1){
                return level;
            }
            if(grid[y][x]==2){
                continue;
            }
            if(grid[y][x]==0){
                //应当在下一层纳入大岛；
                grid[y][x]=2;
                points.push({y,x});
            }
        }
        //当前层的内层已经拓展完
        
      }
       ++level;
    }
    return level;
  }

  void dfs(vector<vector<int>>& grid, int i, int j,queue<pair<int, int>>& points) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
      return;
    }
    if (grid[i][j] == 2||grid[i][j] == 0) {
      return;
    }
    grid[i][j] = 2;
    points.push({i,j});
    for (int k = 0; k < 4; k++) {
      dfs(grid, i + dir[k], j + dir[k + 1],points);
    }
    //好像也不需要额外回溯了？
  }
};