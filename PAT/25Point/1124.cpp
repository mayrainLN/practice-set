#include"bits/stdc++.h"
#include <unordered_set>
using namespace std;
int main(){
    int n,div,first;
    map<string,int> winners;
    cin>>n>>div>>first;
    int k=first;
    for(int i=1;i<=n;i++){
        string tem;
        cin>>tem;
        //应该得奖
        if(i==k){
            // 没得过奖
            if(winners.count(tem)==0){
                cout<<tem<<endl;
                winners[tem]=1;
                k+=div;
            }
            else{
                //下一个
                k++;
                continue;
            }
        }
    }
    if(first>n){
        cout<<"Keep going..."<<endl;
    }
    return 0;
}