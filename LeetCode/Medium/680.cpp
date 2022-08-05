#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool validPalindrome(string s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                int r1 = r - 1, l1 = l;
                int r2 = r, l2 = l + 1;
                //切右边
                while (l1 < r1)
                {
                    if (s[l1] == s[r1])
                    {
                        l1++;
                        r1--;
                    }
                    else break;
                }
                if(l1 >= r1) return true;

                 while (l2 < r2)
                {
                    if (s[l2] == s[r2])
                    {
                        l2++;
                        r2--;
                    }
                    else
                        return false;
                }
                return true;
            }
        }
        return true;
    }
};
int main()
{
    Solution sol;
    string s = "axbcbaba";
    sol.validPalindrome(s);
    return 0;
}