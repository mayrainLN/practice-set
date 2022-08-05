#include"bits/stdc++.h"
using namespace std;
vector<int> nodes[100000];
bool visit[100000]={false};
int minheight=1000000000;
int minnum=0;
void dfs(int i,int h){
    visit[i]=true;
    if(h<minheight&&nodes[i].size()==0){
        minheight=h;
        minnum=1;
    }else if(h==minheight&&nodes[i].size()==0){
        minnum++;
    }
    for(auto& it:nodes[i]){
        if(visit[it]==false){
            dfs(it,h+1);
        }
    }
}
// vector<int
int main(){
    int n;
    double origin,percent;
    cin>>n>>origin>>percent;
    //建树
    for(int i=0;i<n;i++){
        int num,tem;
        cin>>num;
        while(num--){
            cin>>tem;
            nodes[i].push_back(tem);
        }
    }
    dfs(0,1);
    minheight=minheight-1;
    while(minheight--){
        origin*=(1+percent/100);
    }
    printf("%.4f %d\n",origin,minnum);
    return 0;
}