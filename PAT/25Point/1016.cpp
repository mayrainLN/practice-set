#include "bits/stdc++.h"
using namespace std;

int rate[25] = {0};
//每次的账单记录
class temRec {
 public:
  int month = 0;
  int d = 0, h = 0, m = 0;
  bool status = false;  // true 上线，false 下线
  temRec(int tMon, int tDay, int tHou, int tMin, bool tSta) {
    month = tMon;
    d = tDay;
    h = tHou;
    m = tMin;
    status = tSta;
  }
};

bool cmp(temRec x, temRec y) {
  if (x.month != y.month) {
    return x.month < y.month;
  } else if (x.d != y.d) {
    return x.d < y.d;
  } else if (x.h != y.h) {
    return x.h < y.h;
  } else
    return x.m < y.m;
}

// 传入两条几率，得到间隔时间。
int getTime(temRec& x, temRec& y) {
  //如果不符
  if (!(x.status == true && y.status == false && x.month == y.month)) {
    return 0;
  }
  return y.m + y.h * 60 + y.d * 60 * 24 - x.m - x.h * 60 - x.d * 60 * 24;
}

double getFee(temRec& x, temRec& y) {
  // 计算距离每月最起点的话费
  // rate[24]里是24小时比率之和。*60后即可得到一天的费用 相当于(1+2+3...)*1*60;
  int totalx = rate[x.h] * x.m + rate[24] * 60 * x.d;
  int totaly = rate[y.h] * y.m + rate[24] * 60 * y.d;
  for (int i = 0; i < x.h; i++) {
    totalx += rate[i] * 60;
  }
  for (int i = 0; i < y.h; i++) {
    totaly += rate[i] * 60;
  }
  return (totaly - totalx) / 100.0;
}

int main() {
  for (int i = 0; i <= 23; i++) {
    int x;
    cin >> x;
    rate[i] = x;
    rate[24] += rate[i];
  }
  int N;
  cin >> N;

  map<string, vector<class temRec>> callList;
  int tMon, tDay, tHou, tMin;
  string tst;
  bool tSta;
  string Tname;
  for (int i = 0; i < N; i++) {
    cin >> Tname;
    scanf("%d:%d:%d:%d", &tMon, &tDay, &tHou, &tMin);
    cin >> tst;
    if (tst == "on-line") {
      tSta = true;
    } else {
      tSta = false;
    }

    //不存在该key，创建新的vector
    if (callList.find(Tname) == callList.end()) {
      // 创建一个新数据项
      temRec t = temRec(tMon, tDay, tHou, tMin, tSta);
      // 创建一个新vector
      vector<class temRec> v = {t};
      // 插入通话记录
      callList[Tname] = v;
    } else {
      // 如果已经存在key，直接加在vector后面；
      auto it = callList.find(Tname);
      it->second.push_back(temRec(tMon, tDay, tHou, tMin, tSta));
    }

    callList[Tname].push_back(temRec(tMon, tDay, tHou, tMin, tSta));
  }

  // 给内部电话记录按照时间排序。
  for (auto i = callList.begin(); i != callList.end(); i++) {
    sort(i->second.begin(), i->second.end(), cmp);
  }

  // 计算 用一下新的遍历语法
  for (auto i : callList) {
    // 每个人
    double totFee = 0;
    bool flag = true;  //记录是否需要打印月份
    bool consume = false;
    // bool change=false;
    int dd, hh, mm;
    for (auto ii = i.second.begin(); ii != i.second.end() - 1; ii++) {
      if (flag) {
        cout << i.first;
        printf(" %02d\n", (*ii).month);
        flag = false;
        consume = true;
      }

      // 每通电话
      int time = getTime(*ii, *(ii + 1));
      double fee = getFee(*ii, *(ii + 1));
      if (time != 0) {
        printf("%02d:%02d:%02d %02d:%02d:%02d ", (*ii).d, (*ii).h, (*ii).m,
               (*(ii + 1)).d, (*(ii + 1)).h, (*(ii + 1)).m);
        printf("%d $%.2f\n", time, fee);
        totFee += fee;
      }
    }
    if (totFee!=0) {
      cout << "Total amount: $";
      printf("%.2f\n", totFee);
    }
  }

  // 数据储存完毕，开始计算
  return 0;
}