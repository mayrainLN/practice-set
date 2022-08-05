#include"bits/stdc++.h"
using namespace std;
const int MAXN=1001;
int father[MAXN]; //father[i]表示用户i的父节点编号。
int groupSize[MAXN]={0}; //记录根代表的集合的元素数目

int findFather(int x) {
    int leaf=x;
    while(father[x]!=x){
        x=father[x];
    }
    //x已经变成根
    while(father[leaf]!=leaf){
        //记录叶子位置
        int r=leaf;
        //叶子父亲的位置为下一个循环的叶子
        leaf=father[leaf];
        //叶子已经改变，则将记录的叶子位置 指向根
        father[r]=x;
    }
    return x;
}

void Union(int b,int a){
    int fa=findFather(a);
    int fb=findFather(b);
    //根一样，无需合并
    if(fa==fb){
        return;
    }
    //合并两集合的元素数目
    groupSize[fb]+=groupSize[fa];
    //将fa合并到fb
    father[fa]=fb;
    groupSize[fa]=0;
}

void incre(int x){
    //每个人输入后，增加x的根所代表的集合的元素数目
    groupSize[findFather(x)]++;
}


int main(){
    int n;
    scanf("%d",&n);
    //初始化
    for(int i=0;i<MAXN;i++){
        father[i]=i;
    }

    for(int i=1;i<=n;i++){
        int nn;
        int root;
        scanf("%d: %d",&nn,&root);
        //循环n-1次

        while(--nn){
            int cid;
            scanf("%d",&cid);
            Union(root,cid);
        }
        incre(root);
    }

    //计算存在几个集合
    int cnt=0;
    vector<int> ans;
    for(int i=0;i<MAXN;i++){
        if(father[i]==i&&groupSize[i]>0){
            cnt++;
            ans.push_back(groupSize[i]);
        }
    }
    sort(ans.begin(),ans.end(),greater<int>());

    cout<<cnt<<endl;
    for(int i=0;i<ans.size();i++){
        if(i==0){
            cout<<ans[i];
        }
        else cout<<" "<<ans[i];
    }
    system("pause");
    return 0;
}
