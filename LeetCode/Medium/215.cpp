#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  void swap(vector<int>& nums, int i, int j) {
    int tem = nums[i];
    nums[i] = nums[j];
    nums[j] = tem;
  }
  void swapIndex(int& i, int& j) {
    int tem = i;
    i = j;
    j = tem;
  }
  int findPivot(vector<int>& nums, int i, int j)
  //在[i,j]将数轴归位，返回数轴的！！！xian
  {                 //找第k个最大的元素，应该从大到小
    int pivot = i;  //默认第一个为数轴
    int another = j;
    while (pivot != another) {
      if (nums[pivot] < nums[another] &&
          pivot < another) {         // 数轴较小,且位置在前面
        swap(nums, pivot, another);  //交换位置，现在p位于j；
        swapIndex(another, pivot);   //数轴交换
        if (another > pivot) {
          --another;
        } else {
          ++another;
        }
      } else if (nums[pivot] > nums[another] && pivot > another) {
        //数轴较大，位置在后面
        swap(nums, pivot, another);  //交换位置，现在p位于j；
        swapIndex(another, pivot);   //数轴交换
        if (another > pivot) {
          --another;
        } else {
          ++another;
        }
      } else {
        //继续搜寻
        if (another > pivot) {
          --another;
        } else {
          ++another;
        }
      }
    }
    return pivot;
  }

  int findKthLargest(vector<int>& nums, int k) {
    //   if(div<k){//归位的轴的位置小于k,在右边
    //     findPivot(nums,k+1,nums.size())
    //   }
    int l = 0, r = nums.size() - 1;

    while (l < r) {
      int div = findPivot(nums, l, r);
      if (div == k-1) {
        return nums[div];
      } else if (div < k-1) {
        // k在div右边
        l = div + 1;
      } else {
        // k在div左边
        r = div - 1;
      }
    }
    return nums[l];
  }
};

void trimLeftTrailingSpaces(string& input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string& input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

vector<int> stringToIntegerVector(string input) {
  vector<int> output;
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);
  stringstream ss;
  ss.str(input);
  string item;
  char delim = ',';
  while (getline(ss, item, delim)) {
    output.push_back(stoi(item));
  }
  return output;
}

int stringToInteger(string input) { return stoi(input); }

int main() {
  string line;
  while (getline(cin, line)) {
    vector<int> nums = stringToIntegerVector(line);
    getline(cin, line);
    int k = stringToInteger(line);

    int ret = Solution().findKthLargest(nums, k);

    string out = to_string(ret);
    cout << out << endl;
  }
  return 0;
}