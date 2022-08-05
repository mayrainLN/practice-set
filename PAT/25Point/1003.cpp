#include "bits/stdc++.h"
using namespace std;
const int INF = 1000000000;  //定义无穷大

int main() {
  int peoNum[500] = {0};
  int pathNum[500] = {0};  //路径数目
  int totalP[500] = {0};
  bool visited[500] = {false};  //顶点是否访问的标记数组
  int minDis[500];              //各顶点距离起点的最短距离
  int adj[500][500];            //图的邻接矩阵
  int cityNum, wayNum, start, destin;

  cin >> cityNum >> wayNum >> start >> destin;
  int c1, c2, d;

  //初始化
  fill(adj[0], adj[0] + 500 * 500, INF);
  fill(minDis, minDis + 500, INF);
  minDis[start] = 0;
  pathNum[start] = 1;

  //存储点权
  for (int i = 0; i < cityNum; i++) {
    int n;
    cin >> n;
    peoNum[i] = n;
  }

  totalP[start] = peoNum[start];

  for (int i = 0; i < wayNum; i++) {
    cin >> c1 >> c2 >> d;
    adj[c1][c2] = adj[c2][c1] = d;
  }

  // 开始dijkstra
  for (int i = 0; i < cityNum; i++) {
    // 先找到未被访问节点中最近顶点u
    int u = -1, minD = INF, maxP = 0;
    for (int j = 0; j < cityNum; j++) {
      //未被访问且最短距离小或者最短路径相等且最少花费小
      if (visited[j] == false &&
          (minDis[j] < minD || minDis[j] == minD && maxP < peoNum[j])) {
        u = j;
        minD = minDis[j];
        maxP = peoNum[j];
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
      // dis借助u到达j更优
      if (minDis[j] > minDis[u] + adj[u][j]) {
        minDis[j] = minDis[u] + adj[u][j];
        pathNum[j] = pathNum[u];
        totalP[j] = totalP[u] + peoNum[j];
      }
      // peo借助u到达j更优 则dis不用改变
      else if (minDis[j] == minDis[u] + adj[u][j]) {
        if (totalP[j] < totalP[u] + peoNum[j]) {
          totalP[j] = totalP[u] + peoNum[j];
        }
        // ！！！！最短路径条数与点权无关，必须写在外面
          pathNum[j] = pathNum[u] + pathNum[j];

      }
    }
  }

  cout << pathNum[destin] << " " << totalP[destin];
  return 0;
}