#include "bits/stdc++.h"
using namespace std;
typedef struct stu {
  int id, poi;
  string name;
  stu(int id, string name, int poi) : id(id), name(name), poi(poi) {}
};

int main() {
  vector<stu> list;
  int n, c;
  int id, poi;
  string name;
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> id >> name >> poi;
    list.push_back(stu(id, name, poi));
  }
  if (c == 1) {
    sort(list.begin(), list.end(), [](stu x, stu y) -> bool {return x.id < y.id; });
  } else if (c == 2) {
    sort(list.begin(), list.end(),
         [](stu x, stu y) -> bool {return x.name == y.name?x.id<y.id:x.name<y.name; });
  } else {
    sort(list.begin(), list.end(),
         [](stu x, stu y) -> bool {return  x.poi == y.poi?x.id<y.id:x.poi<y.poi; });
  }
  for (auto& it : list) {
      printf("%06d",it.id);
    cout << " " << it.name << " " << it.poi << endl;
  }
  return 0;
}