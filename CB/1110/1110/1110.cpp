#include"bits/stdc++.h"
using namespace std;
int n;
struct node{
    int l,r;
    int index;
    bool father=false;
}nodeList[20];
//bool father={false};

int exsit[100]={-1};
void create(int cur,int root){
    //ÖÐÐò±éÀúÊ÷£¬ÉèÖÃ
    exsit[root]=nodeList[cur].index;
    if(nodeList[cur].l!=-1){
        create(nodeList[cur].l,root*2);
    }
    if(nodeList[cur].r!=-1){
        create(nodeList[cur].r,root*2+1);
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        nodeList[i].index=i;
        string x,y;
        cin>>x>>y;
        if(x=="-"){
            nodeList[i].l=-1;
        }else{
            nodeList[i].l=stoi(x);
            nodeList[nodeList[i].l].father=true;
        }
        if(y=="-"){
            nodeList[i].r=-1;
        }else{
            nodeList[i].r=stoi(y);
            nodeList[nodeList[i].r].father=true;
        }
    }
    int root;
    for(int i=0;i<n;i++){
        if(nodeList[i].father==false){
            root=i;
        }
    }
    fill(exsit,exsit+100,-1);
    create(root,1);
    bool ans=true;
    for(int i=1;i<=n;i++){
        if(exsit[i]<0){
            ans=false;
            break;
        }
    }
    if(ans){
        cout<<"YES"<<" "<<exsit[n];
    }
    else{
        cout<<"NO"<<" "<<root;
    }
}
