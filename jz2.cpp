#include "stdio.h"

int jc(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++) {
    res = res * i;
  }
  return res;
}

int main() {
  int m, n, res;
  printf("开始计算组合数C(n,m),请输入n，m\n");
  scanf("%d%d", &n, &m);
  if (m < 0 || n < 0) {
    printf("m和n应为正整数\n");
    return 0;
  } else if (n < m) {
    printf("n应大于m\n");
    return 0;
  }
  res = jc(n) / (jc(m) * jc(n - m));
  printf("计算结果为%d", res);
  return 0;
}