#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        //        //
        // 12345678910 11 12 13 14 15 16 178901234
        // ababcbacad  e  f  e  g  d  e  hijhklij
        // 0012043570  0  0  11 0  10 13
        //遍历，记录每个字母第一次出现的位置、最后一次出现的位置。依次找最大范围的字母，在其范围之内的全部去掉。再找，直到空集。
        int PosiReco[501][3];                     //每个字母的位置记录 及宽度
        int flag[26];                             //出现的字母记录
        memset(flag, 0, sizeof(flag));            //两种清零方式。同时注意memset的用法
        for (int i = 0, j = 0; i < s.size(); i++) //i 字符串  j 字母位置记录
        {
                int fir = s.find_first_of(s[i]);
                int las = s.find_last_of(s[i]);
                flag[s[i] - 'a'] = 1; //记录出现的字母
                PosiReco[i][0] = fir;
                PosiReco[i][1] = las;
                PosiReco[i][2] = las - fir;
        }
        vector<int> len;
        int start = PosiReco[0][0], end = PosiReco[0][1];
        for (int i = 1; i < s.size();)
        {
            for (int j = start + 1; j < end; j++)
            {
                if (PosiReco[j][1] > end)
                {
                    end = PosiReco[j][1];
                }
            } //结束时，j已经走到end处；此时找到一个子串
            len.push_back(end-start+1);
            i=end+1; //继续往后找
            start=PosiReco[i][0];
            end = PosiReco[i][1];
        }
        // defegde hij h  k  l  i  j
        // 0123456 789 10 11 12 13 14
        return len;
    }
};
int main()
{
    string S = "ababcbacadefegdehijhklij";
    Solution sol;
    sol.partitionLabels(S);
    return 0;
}