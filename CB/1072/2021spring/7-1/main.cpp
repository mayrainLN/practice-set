#include"bits/stdc++.h"
using namespace std;

const int MAXN=10000;
//�㼶 ����
stack< pair<int,int> > f;
int father[MAXN];

void add(string& s){

    //cout<<"s:"<<s;
    //����㼶
    int i=0;
    while(s[i]==' '){
        i++;
    }
    //iΪǰ��Ŀո��������Դ���㼶
    int data=stoi(s.substr(i));
    //��������
    father[data]=f.top().second;
    // ά����ջ
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
    //���ڵ���ջ���棬λ��ջ��
    //����½ڵ��������ڸ��ڵ�
    //+1���½ڵ���ջ
    //��ͬ�����ڵ��ջ���½ڵ���ջ
    //С�� һֱ��ջ��ֱ�����

    //ÿ��һ���ڵ㣬����ջ���ĸ�Ԫ�أ�����
    //������ʱ��游�ڵ� ���������ң��Ͳ���дdfsһ����������
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
