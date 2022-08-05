#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ans=false;
    void backTrack(vector<vector<char>>& board, string word,vector<vector<bool>>& visited,int index,int i,int j){
        if(i<0||i>board.size()-1||j<0||j>board[0].size()-1){
         //越界
         return;
        }
        if(ans||visited[i][j]){//进入已经访问的节点或者已经得到答案
            return;
        }
        //字符满足，访问
        if(word[index]==board[i][j]){
            visited[i][j]=true;
        }
        else{
            return;
        }
        //检查是否找到
        if(index==word.size()-1){
            ans=true;
            return;
        }
        //往上 下 左 右深度遍历
            backTrack(board, word, visited, index+1, i, j+1);
            backTrack(board, word, visited, index+1, i, j-1);
            backTrack(board, word, visited, index+1, i-1, j);
            backTrack(board, word, visited, index+1, i+1, j);

        //深度递归已经完成(无法继续进行)
        //向上层回溯
        visited[i][j]=false;
        //横向遍历
    }

    bool exist(vector<vector<char>>& board, string word) {
      if(board.empty()){
          return false;
      }
      
      int nrow=board.size();
      int ncol=board[0].size();
      vector<vector<bool>> visited;
      vector<bool> tem;
      tem.resize(ncol,false);
      visited.resize(nrow,tem);
      for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                backTrack(board,word,visited,0,i,j);
            }
       }
      return ans;
    }
};