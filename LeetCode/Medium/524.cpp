#include <bits/stdc++.h>
using namespace std;
bool comp(string s1, string s2)
{
    if (s1.size() > s2.size())
    {
        return true;
    }
    else if (s1.size() == s2.size())
    {
        return s1 < s2;
    }
    else
        return false;
}
class Solution
{
public:
    string findLongestWord(string s, vector<string> &dictionary)
    {
        sort(dictionary.begin(), dictionary.end(), comp);
        for (int i = 0; i < dictionary.size(); i++)
        {
            int p1 = 0;
            int p2 = 0;
            while (p1 < s.size() && p2 < s.size())
            {
                if (s[p1] == dictionary[i][p2])
                {
                    ++p1;
                    ++p2;
                }
                else
                {
                    ++p1;
                }
            }
            if(p2==dictionary[i].size()){
                return dictionary[i];
            }
        }
        string nulls;
        return nulls;
    }
};
int main()
{
    Solution sol;
    return 0;
}