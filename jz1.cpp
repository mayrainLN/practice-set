#include "stdio.h"

void MySort(char* a, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[j] - a[j + 1] > 0) {
        char temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

int main() {
  char a[100] = {'r', 's', 'q', 'j', 'b', 'z', 'a', 'c', 'k', 'h', 'x', 'f'};
  int length = 12;
  MySort(a, length);
  for (int i = 0; i < length; i++) {
    printf("%c ", a[i]);
  }
  return 0;
}