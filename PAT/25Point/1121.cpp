#include"bits/stdc++.h"
using namespace std;
int couple[100000];
bool flag[100000]={false};
int main(){
    fill(flag,flag+100000,false);
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        couple[a]=b;
        couple[b]=a;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int id;
        cin>>id;
        flag[id]=true;
    }

    bool first=true;
    vector<int> ans;
    for(int i=0;i<100000;i++){
        if(flag[i]!=flag[couple[i]]&&flag[i]){
            ans.push_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto& it:ans){
        if(first){
            printf("%05d",it);
            first=false;
        }
        else{
            printf(" %05d",it);
        }
    }
    return 0;
}