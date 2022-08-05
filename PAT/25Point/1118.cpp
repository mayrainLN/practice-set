#include "bits/stdc++.h"
using namespace std;
// 输入多个集合,不同集合间有任何重复就合并
// 1.输出合并后的集合数量，元素数量
// 2.判断任意两个数是否在同一集合
int father[10001] = {0};
set<int> allBirds;
// bool visit[10001] = {false};
// 存储完数据，挨个检查，再合并根
int getRoot(int x){
    int root=father[x];
    while(root!=father[root]){
        root=father[root];
    }
    return root;
}

int Union(int x,int y){
    int fx=getRoot(x);
    int fy=getRoot(y);
    if(fx<fy){
        father[fy]=father[fx];
    }
    else
     father[fx]=father[fy];
}

int main() {
  int N, Q;
  vector<vector<int>> data;
  for (int i = 0; i < 10001; i++) {
    father[i] = i;
  }
  cin >> N;
  for (int i = 0; i < N; i++) {
    int num;
    cin >> num;
    vector<int> tem;
    for (int j = 0; j < num; j++) {
      int id;
      cin >> id;
      allBirds.insert(id);
      tem.push_back(id);
    }
    sort(tem.begin(), tem.end());
    // 以集合中最小元素为根
    for (auto it : tem) {
      //最小的元素
      if (father[it] < tem[0]) {
        // 当前组的根已经有了一个更好的根，所以就不以自己为根
        continue;
      }
      father[it] = tem[0];
    }
    data.push_back(tem);
  }

  sort(data.begin(), data.end(),
       [](vector<int> x, vector<int> y) -> bool { return x[0] < y[0]; });


  int cnt = 0;
  for (auto& it : allBirds) {
    if (father[it] == it) {
      cnt++;
    }
  }

  cout << cnt << " " << allBirds.size() << endl;

  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int x, y;
    cin >> x >> y;
    if (getRoot(x)== getRoot(y)) {
      cout << "Yes" << endl;
    } else
      cout << "No" << endl;
  }
  // 求集合数量
  return 0;
}