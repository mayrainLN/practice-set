#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string frequencySort(string s) {
    // 如果长度太短
    if (s.length() <= 2) {
      return s;
    }
    // 用hash_map(java里的叫法)统计每种字符的数目
    // ，普通map是关联式容器，会自动排序
    unordered_map<char, int> count;
    for (char c : s) {
      count[c]++;
    }
    // 桶排序，按照字符的数目进行排序
    vector<char> res[(s.length() + 1)];  //妈的，其实就是vector的数组
    // res中的每个元素都是一个桶(vector)。用普通数组，会浪费空间
    for (auto& p : count) {
      // p为count map中的item,
      // p.second是每个字母的数量，p.first是字母的index(ascii)
      res[p.second].push_back(p.first);
      // 这样，出现次数相同的字母，就放入了同一个桶
    }
    string ans;
    // 将排序后的字符加入到字符串中
    for (int i = s.length(); i >= 1; i--) {
      //桶按照序号(代表字母出现次数)从大到小排列
      for (int j = 0; j < res[i].size(); j++) {  //遍历每个桶内元素
        for (int k = 0; k < i; k++) {
          ans += res[i][j];
        }
      }
    }
    return ans;
  }
};
int main() {
  Solution sol;
  return 0;
}