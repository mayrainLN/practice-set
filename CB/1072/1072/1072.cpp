#include "bits/stdc++.h"
using namespace std;
const int MAXN = 20000;
const int INF = 100000000;

int mp[MAXN][MAXN]={INF};
int mindis[MAXN]={INF};
int hnum,gnum,wnum,serveDis;
bool visit[MAXN]={false};

int trans(string& v1){
    if(v1[0]=='G'){
        v1=v1.substr(1);
        return hnum+stoi(v1);
    }
    else return stoi(v1);
}

void dij(int start){
    fill(mindis,mindis+MAXN,INF);
    fill(visit,visit+MAXN,false);
    //�������ľ����ʼ��Ϊ0
    mindis[start]=0;

    for(int i=hnum+1;i<=hnum+gnum;i++){
        int minS=INF,u=-1;
        //��δ���ʵĽڵ����ҵ���������Ķ���u
        for(int j=1;j<=hnum+gnum;j++){
            if(!visit[j]&&mindis[j]<minS){
                u=j;
                minS=mindis[j];
            }
        }

        visit[u]=true;
        //��uΪ�н飬������������������̾���
        for(int j=1;j<=hnum+gnum;j++){
            //��uΪ�н����
            if(!visit[j]&&mindis[j]>mindis[u]+mp[u][j]){
                //������̾���
                mindis[j]=mindis[u]+mp[u][j];
            }
        }

    }

}

int main(){
    scanf("%d%d%d%d",&hnum,&gnum,&wnum,&serveDis);
    fill(mp[0], mp[0]+MAXN*MAXN, INF);
    while(wnum--){
        string v1,v2;
        int v11,v22,temDis;
        cin>>v1>>v2>>temDis;
        v11=trans(v1);
        v22=trans(v2);
        mp[v11][v22]=mp[v22][v11]=temDis;
    }

    int ansId=-1;
    double ansAve=INF,ansMin=-1;

    for(int i=hnum+1;i<=gnum+hnum;i++){

        //��ÿ������վλ��dij
        dij(i);

        double temAve=0,temMin=INF;
        bool leap=false;

        for(int j=1;j<=hnum;j++){
            //����������
            if(mindis[j]>serveDis){
                leap=true;
            }
        }
        if(leap){
            continue;
        }

        //������̾����ƽ������  ��Щ���Ǹü���վ����ھ���¥���Ե�
        for(int j=1;j<=hnum;j++){
            //��¼��̾���
            if(temMin>mindis[j]){
                temMin=mindis[j];
            }
            temAve+=mindis[j]*1.0;
        }
        temAve/=hnum;
        //��¼��
        if(ansMin<temMin||ansMin==temMin&&ansAve>temAve||ansMin==temMin&&ansAve==temAve&&ansId>i){
            ansId=i;
            ansMin=temMin;
            ansAve=temAve;
        }
    }

    if(ansId==-1){
        cout<<"No Solution";
        return 0;
    }
    cout<<"G"<<ansId-hnum<<endl;
    printf("%.1f %.1f",round(ansMin*10)/10.0,round(ansAve*10)/10.0);
    return 0;
}
