#include "bits/stdc++.h"
using namespace std;
const int maxn = 200005;
int main() {
  long a[maxn], b[maxn];
  int na, nb;
  cin >> na;
  for (int i = 0; i < na; i++) scanf("%ld", &a[i]);
  cin >> nb;
  for (int i = 0; i < nb; i++) scanf("%ld", &b[i]);

  int pa = 0, pb = 0, k = 0, t = (na + nb-1) / 2;
  while (pa<na&&pb<nb) {
    if (a[pa] < b[pb]) {
      if (k == t) {
        printf("%ld", a[pa]);
        break;
      }
      // pa小，pa往后走
      pa++;
      k++;
    } else {
      if (k == t) {
        printf("%ld", b[pb]);
        break;
      }
      // pb小，pb往后走
      pb++;
      k++;
    }
  }
  if (pa == na || pa == nb) {
    if (pa == na) {
      // a已经走完，a所有的数都在中位数左边
      printf("%ld", b[t - pa]);
    } else if (pb == nb) {
      printf("%ld", a[t - pb]);
    }
  }
  return 0;
}