#include "bits/stdc++.h"
using namespace std;
const int INF = 1000000000;  //定义无穷大
int pre[500];  //存储从起点到达v的最短路径上，pre[v]为该路径上的前一个顶点；

// 纯Dijkstra
void DFS(int v) {
  if (v == 0) {
    cout << v << endl;
    return;
  }
  DFS(pre[v]);
  cout << v << endl;
}

int main() {
  int adj[500][500] ;  //图的邻接矩阵
  // int dis[500][500];
  int cost[100][500];
  bool visited[500] = {false};  //顶点是否访问的标记数组
  int cityNum, wayNum, start, destin;
  int minDis[500];   //各顶点距离起点的最短距离
  int minCost[500];  //最少花费
  // -----------------------------------------------------------------------
  cin >> cityNum >> wayNum >> start >> destin;
  int c1, c2, d, c;

  //初始化
  fill(adj[0], adj[0] + 500 * 500, INF);
  fill(cost[0], cost[0] + 500 * 500, INF);
  fill(minDis, minDis + 500, INF);
  fill(minCost, minCost + 500, INF);

  for (int i = 0; i < wayNum; i++) {
    cin >> c1 >> c2 >> d >> c;
    adj[c1][c2] = adj[c2][c1] = d;
    cost[c1][c2] = cost[c2][c1] = c;
  }
  minDis[start] = 0;
  minCost[start] = 0;

  // 开始dijkstra
  for (int i = 0; i < cityNum; i++) {
    // 先找到未被访问节点中最近顶点u
    int u = -1, minD = INF, minC = INF;
    minDis[start] = 0, minCost[start] = 0;
    for (int j = 0; j < cityNum; j++) {
      //未被访问且最短距离小或者最短路径相等且最少花费小
      if (visited[j] == false &&
          (minDis[j] < minD || minDis[j] == minD && minCost[j] < minC)) {
        u = j;
        minD = minDis[j];
        minC = minCost[j];
      }
    }

    //没找到,说明剩下未被访问的节点与起点不连通，分别位于两个连通分量
    if (u == -1) {
      // return 0;
      continue;
    }

    visited[u] = true;
    // 将找到的u和起点划分在一起，看做一个新的(连通分量)，更新剩下未被访问节点与其的边权
    for (int j = 0; j < cityNum; j++) {
      // 若以u为中介点可以使dis[u]更小或者dis[u]相等的情况下，cost[u]更小
      if (visited[j] == false && adj[u][j] !=INF) {
        if (minDis[j] > minDis[u] + adj[u][j]) {  //距离小
          minDis[j] = minDis[u] + adj[u][j];
          minCost[j] = minCost[u] + cost[u][j];

          pre[j] = u;
        } else if (minDis[j] == minDis[u] + adj[u][j] &&
                   minCost[j] > minCost[u] + cost[u][j]) {  //距离相同，花费小
          minCost[j] = minCost[u] + cost[u][j];
          pre[j] = u;
        }
      }
    }
  }

  cout << "begin" << endl;
  DFS(3);

  cout << "over";

  return 0;
}