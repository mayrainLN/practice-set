#include "bits/stdc++.h"
using namespace std;

const int INF = 1000000000;
typedef struct person {
  int id = INF;  //四位数
  int fid, mid;
  int cnum = 0;
  int cid[6];
  int houseN;
  int houseA;
};
//存储各个节点从属信息
int rela[10001];
// 求人数时
bool flag[10001] = {false};

typedef struct family {
  int id, people;
  double houseNum, houseArea;
  bool flag = false;  //该family是否是有效数据
};

bool visit[10001] = {false};  //为flag[id]=true则他已经被统计过
                              // person list[1001];

int getRoot(
    int id) {  //从并查集中获取该节点的根，初始化时每个节点的根节点都是自己
  while (rela[id] != id) {
    id = rela[id];
  }
  return id;
}

int Union(int& x, int& y) {
  int xx = getRoot(x);
  int yy = getRoot(y);
  //   ！！！合并的是根
  // 指向有关联的最小根
  //   !!!!合并是两两合并 当然要两个参数
  // (即将一个元素指向的根，换成另外一个元素指向的根)
  if (xx < yy) {
    rela[yy] = xx;
  } else if (yy < xx) {
    rela[xx] = yy;
  }
}

int main() {
  int N, id;
  person list[1001];
  family ans[10001];  //关于户主id的映射
  // 初始化关系
  for (int i = 0; i < 10001; i++) {
    rela[i] = i;
  }

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> id;
    list[i].id = id;
    cin >> list[i].fid >> list[i].mid >> list[i].cnum;
    for (int j = 0; j < list[i].cnum; j++) {
      cin >> list[i].cid[j];
    }
    cin >> list[i].houseN >> list[i].houseA;

    // 数据输入完毕；顺便完成Union。
    // 不必用排列组合出所有可能
    // 每个人的初始户主都是自己(自己为根)，将他与其他家庭成员的户主合并
    if (list[i].fid != -1) {
      Union(list[i].fid, list[i].id);
    }
    if (list[i].mid != -1) {
      Union(list[i].mid, list[i].id);
    }
    for (int j = 0; j < list[i].cnum; j++) {
      Union(list[i].cid[j], list[i].id);
    }
  }

  //将储存的数据存入ans
  for (int i = 0; i < N; i++) {
    int root = getRoot(list[i].id);  //此人的户主
    // if(root==5551){
    //     int is=0;
    // }
    // 找到的一定是户主
    ans[root].id = root;
    ans[root].flag = true;  //此人是户主
    ans[root].houseArea += 1.0* list[i].houseA;
    ans[root].houseNum +=1.0* list[i].houseN;
    //家庭人数有重叠
    if (visit[list[i].id] == false) {
      ans[root].people++;
      visit[list[i].id] = true;
    }
    if (list[i].fid != -1) {
      if (visit[list[i].fid] == false) {
        ans[root].people++;
        visit[list[i].fid] = true;
      }
    }
    if (list[i].mid != -1) {
      if (visit[list[i].mid] == false) {
        ans[root].people++;
        visit[list[i].mid] = true;
      }
    }
    for (int j = 0; j < list[i].cnum; j++) {
      if (visit[list[i].cid[j]] == false) {
        ans[root].people++;
        visit[list[i].cid[j]] = true;
      }
    }
  }

  int cnt;
  //计算平均
  for (int i = 0; i < 10001; i++) {
    if (ans[i].flag == false) {
      continue;
    }
    cnt++;
    ans[i].houseArea =1.0* ans[i].houseArea  / ans[i].people;
    ans[i].houseNum = 1.0 * ans[i].houseNum  / ans[i].people;
  }

  sort(ans, ans + 10001, [](family x, family y) -> bool {
    if (x.houseArea != y.houseArea) {
      return x.houseArea > y.houseArea;
    } else
      return x.id < y.id;
  });
  printf("%d\n",cnt);
  for (int i = 0; i < cnt; i++) {
    printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].houseNum,
           ans[i].houseArea);
  }

  return 0;
}