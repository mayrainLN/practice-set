#include "bits/stdc++.h"
using namespace std;

typedef struct node {
  char data = '#';
  int next = -1;
}node;

int main() {
  node list[100005];
  bool flag[100005] = {false};
  int begin1, begin2, nodeNum, add;
  cin >> begin1 >> begin2 >> nodeNum;
  for (int i = 0; i < nodeNum; i++) {
    //   scanf("%d",&add);
    //   scanf("%d%c%d",&list[add].data,&list[add].next);
    cin >> add;
    cin >> list[add].data >> list[add].next;
  }
  //   遍历第一个字符串，记录出现的字符
  while (begin1 != -1) {
    flag[begin1] = true;
    begin1 = list[begin1].next;
  }

  while(begin2!=-1){
      if(flag[begin2]){
          printf("%05d",begin2);
          return 0;
      }
      begin2 = list[begin2].next;
  }

  cout<<"-1";
  return 0;
}