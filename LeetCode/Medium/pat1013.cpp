#include "bits/stdc++.h"
using namespace std;
// 切掉某个顶点，为保持图的连通，需要加入几条边

int citynum, waynum, checknum;
vector<int> ways[1001];  //根据城市id存储waynum；双向，伪邻接表存储
vector<int> check;
bool visited[1001] = {false};  //城市是否访问
int c1, c2;

void dfs(int cityIndex, int wayIndex = 0) {  //默认访问第一个路径
  //访问该城市
  visited[cityIndex] = true;

  while (visited[ways[cityIndex][wayIndex]]) {  //该路径指向的城市已经被访问,找到未被访问的
    ++wayIndex;
  }
  if (wayIndex > ways[cityIndex].size()) {  //该城市所有路径都被走过了
    return;
  }
  //没返回，找到了可以访问的城市了
  //根据该路径访问邻接城市
  dfs(ways[cityIndex][wayIndex]);
}

int mian() {
  // 存入城市数，路径树，检查点数
  cin >> citynum >> waynum >> checknum;
  //存储way
  for (int i = 0; i < waynum; i++) {
    cin >> c1 >> c2;
    ways[c1].push_back(c2);
    ways[c2].push_back(c1);
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
    int count=0;
    for (int j = 1; j <= citynum; j++) {
      if(visited[j]){
          continue;
      }
      dfs(j);
      //dfs完后，一个连通分量已经搜索完
      ++count;
    }
    
    //已经检查完一个测试点
    if(i==0){
      cout<<count-1;
    }
    else{
      cout<<' '<<count-1;
    }
  }
  return 0;
}