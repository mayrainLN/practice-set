#include "bits/stdc++.h"
using namespace std;


void dfs(int& maxdepth,int depeth, int id,vector<int> v[],int rec[]) {
  // 该节点无子节点
  if (v[id].size() == 0) {
    rec[depeth]++;
    return;
  }

  //更新深度
  maxdepth=depeth+1>maxdepth?depeth+1:maxdepth;

  // 存在子节点，继续往其孩子节点寻找
  for (int i = 0; i < v[id].size(); i++) {
    // 值传递，是隐藏的回溯
    dfs(maxdepth, depeth + 1,v[id][i],v,rec);
  }
}

int main() {
  int N, M;            //总节点数，叶子节点数
    int pid, cnum, cid;  //父母id，孩子个数，孩子id
    int rec[100] = {0};  //记录每层叶子节点个数
    vector<int> v[100];  //记录i节点的孩子节点们
    int maxdepth = 1;   //深度

  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    cin >> pid >> cnum;
    for (int j = 0; j < cnum; j++) {
      cin >> cid;
      v[pid].push_back(cid);
    }
  }

  dfs(maxdepth,1,1,v,rec);

  for(int i=1;i<=maxdepth;i++){
      if(i!=1){
          cout<<' ';
      }
      cout<<rec[i];
  }
}