#include "bits/stdc++.h"
using namespace std;
typedef struct course {
  int id;
  int num;
  priority_queue< string,vector<string>,greater<string> > stu;
  course(int _id)   {
      id=_id;
      num=0;
  }
  course()   {
      num=0;
  }
}course;

int main() {
  int nStu, nCou;
  vector<course> courseList;
  //第一个占位
  courseList.resize(1);
  cin >> nStu >> nCou;
  for(int i=1;i<=nCou;i++){
      courseList.push_back(course(i));
  }
  for (int i = 0; i < nStu; i++) {
    int temN,cid;
    string temName;
    cin >> temName >> temN;
    for(int j=0;j<temN;j++){
        cin>>cid;
        courseList[cid].num++;
        courseList[cid].stu.push(temName);
    }
  }
  for(int i=1;i<=nCou;i++){
      cout<<courseList[i].id<<" "<<courseList[i].num<<endl;
      while(!courseList[i].stu.empty()){
          cout<<courseList[i].stu.top();
          printf("\n");
          courseList[i].stu.pop();
      }
  }
  return 0;
}