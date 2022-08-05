#include"bits/stdc++.h"
using namespace std;
const int MAXN=1001;
int father[MAXN]; //father[i]��ʾ�û�i�ĸ��ڵ��š�
int groupSize[MAXN]={0}; //��¼������ļ��ϵ�Ԫ����Ŀ

int findFather(int x) {
    int leaf=x;
    while(father[x]!=x){
        x=father[x];
    }
    //x�Ѿ���ɸ�
    while(father[leaf]!=leaf){
        //��¼Ҷ��λ��
        int r=leaf;
        //Ҷ�Ӹ��׵�λ��Ϊ��һ��ѭ����Ҷ��
        leaf=father[leaf];
        //Ҷ���Ѿ��ı䣬�򽫼�¼��Ҷ��λ�� ָ���
        father[r]=x;
    }
    return x;
}

void Union(int b,int a){
    int fa=findFather(a);
    int fb=findFather(b);
    //��һ��������ϲ�
    if(fa==fb){
        return;
    }
    //�ϲ������ϵ�Ԫ����Ŀ
    groupSize[fb]+=groupSize[fa];
    //��fa�ϲ���fb
    father[fa]=fb;
    groupSize[fa]=0;
}

void incre(int x){
    //ÿ�������������x�ĸ�������ļ��ϵ�Ԫ����Ŀ
    groupSize[findFather(x)]++;
}


int main(){
    int n;
    scanf("%d",&n);
    //��ʼ��
    for(int i=0;i<MAXN;i++){
        father[i]=i;
    }

    for(int i=1;i<=n;i++){
        int nn;
        int root;
        scanf("%d: %d",&nn,&root);
        //ѭ��n-1��

        while(--nn){
            int cid;
            scanf("%d",&cid);
            Union(root,cid);
        }
        incre(root);
    }

    //������ڼ�������
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
