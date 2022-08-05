#include "bits/stdc++.h"
using namespace std;
typedef struct stu {
  string id;
  int posi;
  int points, fRank, lRank;
  stu(string _id, int _points, int _posi) {
    id = _id;
    points = _points;
    posi = _posi;
    fRank = 0;
    lRank = 0;
  }
} stu;

int main() {
  int N, n;
  cin >> N;
  string temId;
  int temPoints;
  vector<stu> pList[100];  //各个考场名单
  vector<stu> tList;
  for (int i = 0; i < N; i++) {
    cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> temId >> temPoints;
      pList[i].push_back(stu(temId, temPoints, i + 1));
    }
    sort(pList[i].begin(), pList[i].end(), [](stu x, stu y) -> bool {
      return x.points == y.points?x.id<y.id:x.points>y.points;
    });
    // 排序完成;计算排名
    int rank = 0, same = 0, last = -1;
    for (auto& it : pList[i]) {
      if (it.points == last) {
        same++;
      } else {
        rank += same + 1;
        same = 0;
      }
      it.lRank = rank;
      last = it.points;
    }
  }
  //各个考场计算完毕
  // 将N个vector合并
  for (int i = 0; i < N; i++) {
    tList.insert(tList.end(), pList[i].begin(), pList[i].end());
  }

  sort(tList.begin(), tList.end(),
       [](stu x, stu y) -> bool { return x.points == y.points?x.id<y.id:x.points>y.points; });

  int rank = 0, same = 0, last = -1;
  for (auto& it : tList) {
    if (it.points == last) {
      same++;
    } else {
      rank += same + 1;
      same = 0;
    }
    it.fRank = rank;
    last = it.points;
  }

  cout << tList.size() << endl;
  for (auto it : tList) {
    cout << it.id << " " << it.fRank << " " << it.posi << " " << it.lRank
         << endl;
  }
  return 0;
}