#include "bits/stdc++.h"
using namespace std;
// 切掉某个顶点，为保持图的连通，需要加入几条边

int citynum, waynum, checknum;
bool ways[1001][1001]; //根据城市id存储waynum；双向，邻接矩阵存储
vector<int> check;//要检查的城市id
bool visited[1001] = {false};  //城市是否访问
int c1, c2;

void dfs(int cityIndex) {  //默认访问第一个路径
  //访问该城市
  visited[cityIndex] = true;

  //访问该城市的所有路径
  for(int i=1;i<=citynum;i++){
      //有通向某城市的路且该城市未被访问
      if(!visited[i]&&ways[cityIndex][i]){
        dfs(i);
      }
  }   
}

int main() {
  // 存入城市数，路径树，检查点数
  cin >> citynum >> waynum >> checknum;
  //存储way
  for (int i = 0; i < waynum; i++) {
    cin >> c1 >> c2;
    ways[c1][c2]=true;
    ways[c2][c1]=true;
  }

  //存储检查点
  for (int i = 0; i < checknum; i++) {
    int city;
    cin >> city;
    check.push_back(city);
  }

  // 去掉某个城市，检查要新加几条路
  for (int i = 0; i < checknum; i++) {
    memset(visited, false, sizeof(visited));
    // 直接设置去掉的城市已访问即可
    visited[check[i]] = true;
    // 直接for里dfs即可，每次dfs完，就已经将一个连通分量遍历完了，然后count++
    // 想起了袁嵩的话
    int count = 0;
    
    for (int j = 1; j <= citynum; j++) {
      if (visited[j]) {
        continue;
      }
      dfs(j);
      // dfs完后，一个连通分量已经搜索完
      ++count;
    }

    //已经检查完一个测试点
  
      cout << count - 1<<endl;
 
  }
  return 0;
}