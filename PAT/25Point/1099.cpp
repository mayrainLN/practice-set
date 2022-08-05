#include "bits/stdc++.h"
using namespace std;

typedef struct node {
  int id = -1;
  int l = -1;
  int r = -1;
  int data;
};

vector<int> indexOrder;
node nodeList[101];

int ii = 0;
void save(int data[], int cur) {
  if (nodeList[cur].l > 0) {
    save(data, nodeList[cur].l);
  }
  nodeList[cur].data = data[ii];
  ii++;
  if (nodeList[cur].r > 0) {
    save(data, nodeList[cur].r);
  }
}

queue<int> q;
void level(int cur) {
  q.push(cur);
  //遍历每层
  while (!q.empty()) {
    //队列中为节点下标
    int x = q.front();
    q.pop();
    if (x == 0) {
      cout << nodeList[x].data;
    } else {
      cout << " " << nodeList[x].data;
    }
    //子节点入队
    if (nodeList[x].l > 0) {
      q.push(nodeList[x].l);
    }
    if (nodeList[x].r > 0) {
      q.push(nodeList[x].r);
    }
  }
}

int main() {
  int data[101];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    nodeList[i].id = i;
    cin >> nodeList[i].l >> nodeList[i].r;
  }
  //   inOrder(0);
  for (int i = 0; i < n; i++) {
    cin >> data[i];
  }
  sort(data, data + n);
  // 存入数据
  save(data, 0);

    level(0);
  return 0;
}
