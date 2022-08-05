#include "bits/stdc++.h"
using namespace std;
bool isPrime(int x) {
  if(x==1)
  return false;
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  bool first = true;
  int hash[10001];  //从数字映射到位置hash[x%size]=x;
  int index[10001];
  fill(hash, hash + 10001, -1);
  int size, num;
  cin >> size >> num;
  while (!isPrime(size)) {
    size++;
  }
  while (num--) {
    int tem;
    cin >> tem;
    if (!first) {
      cout << " ";
    }
    int pos = tem % size, j;
    for (j = 0; j <size; j++) {
      int p = (pos + j * j)%size;
      if (hash[p ] == -1) {
        hash[p ] = tem;
        cout << p ;
        break;
      }
    }
    if (j >= size) {
      cout << "-";
    }

    first = false;
  }
  return 0;
}