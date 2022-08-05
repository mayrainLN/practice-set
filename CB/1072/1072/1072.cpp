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
    //起点自身的距离初始化为0
    mindis[start]=0;

    for(int i=hnum+1;i<=hnum+gnum;i++){
        int minS=INF,u=-1;
        //在未访问的节点中找到距离最近的顶点u
        for(int j=1;j<=hnum+gnum;j++){
            if(!visit[j]&&mindis[j]<minS){
                u=j;
                minS=mindis[j];
            }
        }

        visit[u]=true;
        //以u为中介，更新其余点与起点间的最短距离
        for(int j=1;j<=hnum+gnum;j++){
            //以u为中介更近
            if(!visit[j]&&mindis[j]>mindis[u]+mp[u][j]){
                //更新最短距离
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

        //对每个加油站位置dij
        dij(i);

        double temAve=0,temMin=INF;
        bool leap=false;

        for(int j=1;j<=hnum;j++){
            //检验服务距离
            if(mindis[j]>serveDis){
                leap=true;
            }
        }
        if(leap){
            continue;
        }

        //更新最短距离和平均距离  这些都是该加油站相对于居民楼而言的
        for(int j=1;j<=hnum;j++){
            //记录最短距离
            if(temMin>mindis[j]){
                temMin=mindis[j];
            }
            temAve+=mindis[j]*1.0;
        }
        temAve/=hnum;
        //记录答案
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
