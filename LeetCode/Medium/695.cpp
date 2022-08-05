#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int max=0;
    int dfs(vector<vector<int>>& grid,int x,int y){//x行y列
        if(x<0||x>grid.size()-1||y<0||y>grid[0].size()-1){ //这里很坑 一直数组越界 傻逼参数名字有点闹  传进来是i ,j 对应的应该是y ，x 
        //以后还是继续用i j吧
            return 0;
        }
        if(grid[x][y]==0){
            return 0;
        }
        //若没返回，当前位置满足条件
        //搜索到当前位置，置为0；
        grid[x][y]=0;
        // 递归搜索
        return 1+dfs(grid,x-1,y)+dfs(grid,x+1,y)+dfs(grid,x,y-1)+dfs(grid,x,y+1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // for(auto& i:grid){
        //     for(auto& j:i){
        //         max=dfs()
        //     }
        // }  这样写很麻烦，因为这样只能横向遍历。纵向很不好办
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                //为了提高效率，已经搜索过的直接重置为0
                if(grid[i][j]!=0){
                    int tem=dfs(grid,i,j);
                    max=tem>max?tem:max;
                }
            }
        }
        return max;
    }
};
int main()
{
    Solution sol;
    return 0;
}