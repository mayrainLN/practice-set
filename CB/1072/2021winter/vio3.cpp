#include"bits/stdc++.h"
using namespace std;
const int MAXN=20;
//���鼯�ȽϺ�
int father[MAXN];

bool judge(int l,int r){
    while(l!=1){
        if(father[l]==r){
            return true;
        }
        l=father[l];
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    //��ʼ������ʿ�����쵼���ǽ���
    fill(father,father+MAXN,1);
    for(int i=2;i<=n;i++){
        int leader;
        cin>>leader;
        //��¼�쵼
        father[i]=leader;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){

        int cnt=1,f;
        cin>>f;
        for(int i=2;i<=n;i++){
            if(judge(i,f)){
                cnt++;
            }
        }
        cout<<cnt<<" ";

    }
    return 0;
}
