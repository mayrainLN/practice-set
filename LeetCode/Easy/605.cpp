#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if(points.size() < 1) return 0;
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) { //传地址效率高；const安全性
            return a[1] < b[1];                                                             //右边界从小到大
        });

        int arcnum=1;
        int arcp=points[0][1]; //第一箭的位置
        for(int i=0;i<points.size();i++){ //遍历一遍，永远在末端射箭。出现不能扎破的气球，重新射箭
            if(points[i][0]>arcp){//射箭
                arcp=points[i][1]; //记住射箭的位置
                arcnum++;
            }
        }
        return arcnum;
    }
};