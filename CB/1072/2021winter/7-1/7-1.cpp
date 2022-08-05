#include"bits/stdc++.h"
using namespace std;
const int MAXSITE=10001;
const int MAXEVENT=101;
int siteN,eventN;
int main(){
    cin>>siteN>>eventN;
    int report[MAXSITE];
    int times[MAXSITE];
    int alltimes[MAXSITE];

    for(int i=0;i<eventN;i++){
        //某个事件 各个网站
        fill(report,report+siteN+1,0);
        fill(times,times+siteN+1,0);
        for(int j=1;j<=siteN;j++){
            cin>>report[j];
        }
        //对于每个网站，统计差异次数
        for(int j=1;j<=siteN;j++){
            for(int k=1;k<=siteN;k++){
                if(report[j]!=report[k]){
                    times[j]++;
                }
            }
        }
         //统计完毕，找出最多的
        int maxTimes= *max_element(times+1,times+siteN+1);


        //统计出现最多的次数
        for(int j=1;j<=siteN;j++){
            if(maxTimes==times[j]){
                alltimes[j]++;
            }
        }
    }

    //
    printf(" ");
    return 0;
}
