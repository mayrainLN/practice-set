#include"bits/stdc++.h"
using namespace std;

const int MAXN=10000;
//层级 数据
stack< pair<int,int> > f;
int father[MAXN];

void add(string& s){

    //cout<<"s:"<<s;
    //计算层级
    int i=0;
    while(s[i]==' '){
        i++;
    }
    //i为前面的空格数，可以代表层级
    int data=stoi(s.substr(i));
    //存入树中
    father[data]=f.top().second;
    // 维护新栈
    if(i==f.top().first){
        f.pop();
        father[data]=f.top().second;
        f.push({i,data});
    }
    else if(i==f.top().first+1){
        father[data]=f.top().second;
        f.push({i,data});
    }
    else if(i<f.top().first){
        while(i<f.top().first){
            f.pop();
        }

        f.pop();
        father[data]=f.top().second;
        f.push({i,data});
    }
}

int main(){
    //父节点用栈储存，位于栈顶
    //如果新节点深度相对于父节点
    //+1，新节点入栈
    //相同，父节点出栈，新节点入栈
    //小于 一直出栈，直到相等

    //每入一个节点，根据栈顶的父元素，建树
    //建树的时候存父节点 方便最后查找，就不用写dfs一个个搜索了
    f.push({0,0});
    fill(father,father+MAXN,-1);
    //father
    int n;
    scanf("%d",&n);
    string tem;
    cin>>tem;
    string temS;
    getline(cin, temS);
    for(int i=0;i<n-1;i++){
        int level=0;
        getline(cin,temS);
        add(temS);
    }

    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int id;
        cin>>id;
        if(father[id]==-1){
            cout<<"Error: "<<id<<" is not found."<<endl;
            continue;
        }
        vector<int> p;
        while(id!=-1){
            p.push_back(id);
            id=father[id];
        }

        printf("0000");
        for(int j=p.size()-2;j>=0;j--){
            printf("->%04d",p[j]);
        }
        cout<<endl;
    }
    int a;
    return 0;
}
