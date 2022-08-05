#include "bits/stdc++.h"
using namespace std;
int cityNum, wayNum, sId, dId;
int c1, c2, dis, cost;
typedef struct way {
  bool exi = false;
  int dis = INTMAX_MAX;
  int cost = INTMAX_MAX;
};

way ways[501][501];

typedef struct ans {
  vector<int> route;
  int dis;
  int cost;
};

class cmp {
 public:
  bool operator()(ans x, ans y) {
    // 距离-花费从小到大排序
    if (x.dis != y.dis)
      return x.dis > y.dis;
    else
      return x.cost > y.cost;
  }
};

priority_queue<ans, cmp> q;

void dfs(int posi,ans route) {

    if(posi==dId){
        q.push(route);
    }
}

int main() {
  // 找到最短路径(存在第二权值)；
  // 1.暴力dfs，通过优先队列(堆)保存所有路径。或者直接存入数组，最后再直接找最优路径。
  cin >> cityNum >> wayNum >> sId >> dId;
  for (int i = 0; i < wayNum; i++) {
    cin >> c1 >> c2 >> dis >> cost;
    ways[c1][c2].exi = true;
    ways[c1][c2].dis = dis;
    ways[c1][c2].cost = cost;
    ways[c2][c1] = ways[c1][c2];
  }
  return 0;
}