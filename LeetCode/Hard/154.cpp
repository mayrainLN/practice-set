#include <bits/stdc++.h>
#include"iostream"
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        //左边都大于右边||完全有序
        // [4,5,6,7,0,1,4]
        //mid>r 左边有序  最小的在右边
        // [7,0,1,4,4,5,6]
        //mid<r 右边有序||完全有序 最小的在左边
        int l = 0, r = nums.size() - 1;
        int tem = INT32_MAX;
        int mid = (l + r) / 2;
        if(nums.size()==1)
        return nums[0];
        while (l < r)
        {
            if (nums[r] == nums[mid])
            {
                --r;
//若 nums[right]是唯一最小值：那就不可能满足判断条件 nums[mid] == nums[right]
// 若 nums[right]不是唯一最小值，由于 mid < right 而 nums[mid] == nums[right]，即还有最小值存在于 [left, right - 1][left,right−1] 区间，因此不会丢失最小值。
            }
            else if (nums[mid] > nums[r])
            { //左边有序  最小的在右边
                l = mid + 1;
            }
            else if (nums[mid] <= nums[r])
            { //右边有序,最小的在左边  
                r = mid;  //mid可能是最小
            }
             mid = (l + r) / 2;
        }
        // 最终l==r==mid  每次循环之后，都会逼近最小值，结束循环之后，l，r，mid重合，肯定已经在最小值上面了，否则，还可以继续逼近，循环不会结束
        return nums[l];
    }
};
int main()
{
    int n[5]={2,2,2,0,1};
    Solution sol;
    // sol.findMin(n);

    return 0;
}