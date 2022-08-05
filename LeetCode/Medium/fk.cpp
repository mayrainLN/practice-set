#include <iostream>
#include <string>
//#define T = 3
//#define S = 5
using namespace std;
struct student {
  string name;
  int age;
};
struct teacher {
  string name;
  int age;
  student stu[5];
};
void fuzhi(struct teacher tea[], int a, int b) {
  for (int i = 0; i < a; i++) {
    cout << "请输入老师" << i + 1 << "的信息：" << endl;
    cin >> tea[i].name >> tea[i].age;
    for (int t = 0; t < b; t++) {
      cout << "请输入老师" << i + 1 << "的第" << t + 1 << "个学生的信息："
           << endl;
      cin >> tea[i].stu[t].name >> tea[i].stu[t].age;
    }
  }
}
void paixu(struct teacher* p[], int t) {
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < t - 1 - i; t++) {
      if (p[j]->age > p[j + 1]->age) {
        teacher* temp;
        temp = p[j];
        p[j] = p[j + 1];
        p[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    cout << p[i]->name << "\t" << p[i]->age << "\t";
    for (int j = 0; i < 5; j++) {
      cout << p[i]->stu[j].name << "\t" << p[i]->stu[j].age << endl;
    }
  }
}
int main() {
  teacher tea[3];
  fuzhi(tea, 3, 5);
  teacher* p[3] = {&tea[0], &tea[1], &tea[2]};
  paixu(p, 3);
  system("pasue");
}

// for(int i=0;i<a.size();i++){
//     for(int j=i+1;j<a.size();j++){
//         swap(a[j],a[j+1]);
//     }
// }