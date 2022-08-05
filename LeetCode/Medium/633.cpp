#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool judgeSquareSum(int c) {
        int l=0,r=sqrt(c);
        while(l<=r){
            int sum=l*l+r*r;
            if(sum==c)
                return true;
            if(sum<c){
                l++;
            }
            else if(sum>c){
                r--;
            }
        }
        return false;
    }
};
int main()
{
    Solution sol;
    return 0;
}