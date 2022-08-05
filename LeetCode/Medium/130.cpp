#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //矩阵大小 
    int m,n;
    vector<vector<bool>> lefted;
    vector<vector<bool>> visited;
    vector<pair<int, int>> starts;

    void dfs(vector<vector<char>>& board,vector<vector<bool>>& lefted,int ii,int jj){
        // 要保留的位置
        lefted[ii][jj]=true;
        visited[ii][jj]=true;
        // 没有越界 且 未被访问 且 为‘O’
        if(ii-1>=0&&visited[ii-1][jj]==false&&board[ii-1][jj]=='O'){
            dfs(board,lefted,ii-1,jj);
        }
        if(ii+1<m&&visited[ii+1][jj]==false&&board[ii+1][jj]=='O'){
            dfs(board,lefted,ii+1,jj);
        }
        if(jj-1>=0&&visited[ii][jj-1]==false&&board[ii][jj-1]=='O'){
            dfs(board,lefted,ii,jj-1);
        }
        if(jj+1<n&&visited[ii][jj+1]==false&&board[ii][jj+1]=='O'){
            dfs(board,lefted,ii,jj+1);
        }
    }
    void solve(vector<vector<char>>& board) {

        m=board.size(),n=board[0].size();
        // 是否保留初始化
        vector<bool> tem=vector<bool>(n,false);
        for(int i=0;i<m;i++){
            lefted.push_back(tem);
        }
        // lefted=vector<vector<bool>>(m,vector<bool>(false,n));
        
        // 是否已经访问初始化
        for(int i=0;i<m;i++){
            visited.push_back(tem);
        }

        bool findlefted=false;
        // 找到第一个挨着边界的。顺着找与之相邻的即可(dfs)；在矩阵中记录下来。
        // 搜索第一个边界的O
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0||i==m-1||j==0||j==n-1)&&board[i][j]=='O'){
                    starts.push_back({i,j});
                }
            }
        }

        // 找到了，就dfs
        for(auto i:starts){
            dfs(board,lefted,i.first,i.second);
        }

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(!lefted[i][j]&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};