#include "bits/stdc++.h"
using namespace std;

bool node[10001][10001] = {false};
bool visit[10001] = {false};
set<int> maxheightNode;
int maxheight = 0;
int n;

void dfs(int cur, int h) {
  visit[cur] = true;
  if (h > maxheight) {
    maxheight = h;
    maxheightNode.clear();
    maxheightNode.insert(cur);
  } else if (h == maxheight) {
    maxheightNode.insert(cur);
  }
  for (int i = 1; i <= n; i++) {
    if (visit[i] == false && node[cur][i]) {
      dfs(i, h + 1);
    }
  }
}
int main() {
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int tem1, tem2;
    cin >> tem1 >> tem2;
    node[tem1][tem2] = node[tem2][tem1] = true;
  }
  //从第一个节点进行一次dfs
  dfs(1, 1);
  int components = 1;
  for (int i = 1; i <= n; i++) {
    if (!visit[i]) {
      components++;
      dfs(i, 1);
    }
  }
  if (components > 1) {
    printf("Error: %d components\n", components);
    return 0;
  }
  set<int> oldSet = maxheightNode;
  fill(visit, visit + 10001, false);
  int s = *maxheightNode.begin();
  dfs(s, 1);
  for(auto& it:oldSet){
      maxheightNode.insert(it);
  }
  for (auto& it : maxheightNode) {
    cout << it << endl;
  }
  return 0;
}