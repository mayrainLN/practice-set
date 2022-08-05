#include "bits/stdc++.h"
using namespace std;
int father[10001] = {-1};  //为-1表示根。绝对值表示当前集合的元素个数

int getRoot(int x) {
  while (father[x]>= 0) {
    x = father[x];
  }
  return x;
}
int Union(int x, int y) {
  // 为了减少查询路径，将元素个数小的集合，合并到元素个数多的集合上面去
  int fx = getRoot(x);
  int fy = getRoot(y);
  if (fx != fy) {
    if (fx > fy) {
      father[fy] += father[fx];  //将fx合并到fy上去
      father[fx] = fy;
    } else {
      father[fx] += father[fy];  //将fy合并到fx上去
      father[fy] = fx;
    }
  }
  return 0;
}

int main() {
  fill(father, father + 10001, -1);
  int n, maxnum = 0;
  cin >> n;
  while (n--) {
    int birdNum, root;
    cin >> birdNum;
    for (int i = 0; i < birdNum; i++) {
      int id;
      cin >> id;
      maxnum = max(id, maxnum);
      if (i == 0) {
        //每组输入都以第一个元素为根
        root = id;
      } else {  //先以第一个元素为根，与后续的数据合并
        // 1.如果两个元素中的某个元素，是之前某个集合的根，极好
        // 2.如果后续的元素是之前某个集合的叶子
        //   father[root]将被合并到该集合上去，后续的元素也会随着root的路径被合并
        Union(root, id);
      }
    }
  }

  int cnt = 0;
  int num=0;
  for (int i = 1; i <= maxnum; i++) {
    if (father[i] < 0) {
      cnt++;
      num-=father[i];    //number of birds
    }
  }
  cout << cnt << " " << num << endl;

  int q;
  cin >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    if (getRoot(x)== getRoot(y)) {
      cout << "Yes" << endl;
    } else
      cout << "No" << endl;
  }
  return 0;
}