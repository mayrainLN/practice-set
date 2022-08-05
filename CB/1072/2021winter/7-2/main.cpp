#include"bits/stdc++.h"
using namespace std;
//const int MAXN=100001;
const int MAXN=10;
int Next[MAXN]={-1};
int pre[MAXN]={-1};
int data[MAXN];
int two[MAXN][MAXN];

int main(){
    int n;
    cin>>n;
    fill(Next,Next+MAXN,-1);
    fill(pre,pre+MAXN,-1);
    for(int i=0;i<n;i++){
        int nIndex;
        cin>>nIndex;
        data[i]=i;
        Next[i]=nIndex;
        pre[nIndex]=i;
    }

    int start;
    for(int i=0;i<n;i++){
        if(pre[i]==-1){
            start=i;
        }
    }

    for(int i=0;i<n;i++){
        int j=start;
        int Rank=1;
        while(data[j]!=i){
            j=Next[j];
            Rank++;
        }
        cout<<Rank<<" ";
    }
    printf("\n");
    return 0;
}

