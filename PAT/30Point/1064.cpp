#include"bits/stdc++.h"
using namespace std;
int n,nodes[1001]={-1},a[1001],i=1;
vector<int> ans;
void dfs(int cur){
    if(cur>n){
        return;
    }
    dfs(cur*2);
    nodes[cur]=a[i++];
    dfs(cur*2+1);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(1);
    for(int i=1;i<=n;i++){
            if(i==1){
                cout<<nodes[i];
            }else{
                cout<<" "<<nodes[i];
            }
    }
    return 0;
}