#include"bits/stdc++.h"
using namespace std;
const int INF=10000000;
//const int MAXN=1001;

typedef struct ans{
    int money;
    int minute;
}ans;

int packN,wayN,startH,startM,planN;
const int MAXN=101;
int Time[MAXN][MAXN];
//int minTime[MAXN];
int endM[MAXN];
int Y[MAXN]={0};
int P[MAXN]={0};
vector<ans> ansV;


//有边权（时间），点权（如果累积边权大于该点要求，点权会变化）。
//使边权最大，点权最小

//floyd求出任意两点间的最短边权
//根据输入的路线，动态地求出点权。每次的结果存入ans
int main(){
    scanf("%d%d%d:%d",&packN,&wayN,&startH,&startM);
    for(int i=1;i<=packN;i++){
        int h,m;
        scanf("%d:%d%d%d",&h,&m,&Y[i],&P[i]);
        //最晚时间 以零点为基准
        endM[i]=h*60+m;
    }
    fill(Time[0],Time[0]+MAXN*MAXN,INF);
    for(int i=0;i<wayN;i++){
        int v,u,t;
        scanf("%d%d%d",&v,&u,&t);
        Time[u][v]=Time[v][u]=t;
    }

    //floyd
    for(int i=1;i<=packN;i++){
        for(int j=1;j<=packN;j++){
            for(int k=1;k<=packN;k++){
                //以k为中介，两两检查i，j
                if(Time[i][k]!=INF&&Time[j][k]!=INF&&Time[i][k]+Time[k][j]<Time[i][j]){
                    Time[i][j]=Time[i][k]+Time[k][j];
                }
            }
        }
    }

    scanf("%d",&planN);

    for(int i=0;i<planN;i++){
        //输入路径
        bool has[MAXN]={false};
        fill(has,has+MAXN,false);
        bool leap=false;
        vector<int> route;
        route.clear();
        route.push_back(0);
        for(int j=0;j<packN;j++){
            int tem;
            scanf("%d",&tem);
            //路径错误 跳过本轮
            if(has[tem]){
                leap=true;
            }
            has[tem]=true;
            route.push_back(tem);
        }
        route.push_back(0);
        //路径错误 跳过本轮
        if(leap){
            continue;
        }

        //开始计算点权 开始时间按照距离0点的分钟计算
        int temMon=0,temMin=startH*60+startM;

        for(int k=0;k<route.size()-1;k++){
            temMin+=Time[route[k]][route[k+1]];
            //及时
            if(temMin<=endM[route[k+1]]){
                temMon+=Y[route[k+1]];
            }else{
                temMon+=(Y[route[k+1]]-P[route[k+1]]);
            }
        }
        ansV.push_back({temMon,temMin});
    }

    sort(ansV.begin(),ansV.end(),[](ans x,ans y)->bool{
            if(x.money!=y.money){
                return x.money>y.money;
            }else{
                return x.minute<y.minute;
            }
        });
    printf("%d %02d:%02d",ansV[0].money,ansV[0].minute/60,ansV[0].minute-ansV[0].minute/60*60);

    system("pause");
    return 0;
}
