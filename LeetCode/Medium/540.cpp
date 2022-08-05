#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int singleNonDuplicate(vector<int> &nums) {
    //[1,1,2, 4 ,4,8,8]  1 1  2 2 3 3
    //[1,1,2, 2 ,4,8,8]
    // [1,1,2,3, 3 ,4,4,8,8]
    int l = 0, r = nums.size() - 1, mid = (l + r) / 2;
    while (l < r) {
      if (nums[mid] == nums[mid + 1]) {
        if ((r - mid - 1) % 2 == 0) {//左边偶数个
          r = mid - 1;
        } else {//右边偶数个
          l = mid + 2; //妈的这里错了一点
        }
      }

      else if (nums[mid] == nums[mid - 1]) {
        if ((mid - 1 - l) % 2 == 0) {  //左边偶数个
          l = mid + 1;
        } else {  //右边偶数个
          r = mid - 2;
        }
      } else
        return nums[mid];
      mid = (l + r) / 2;
    }
    return nums[mid];
  }
};
int main() {
  Solution sol;
  return 0;
}