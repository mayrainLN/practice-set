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
        //ĳ���¼� ������վ
        fill(report,report+siteN+1,0);
        fill(times,times+siteN+1,0);
        for(int j=1;j<=siteN;j++){
            cin>>report[j];
        }
        //����ÿ����վ��ͳ�Ʋ������
        for(int j=1;j<=siteN;j++){
            for(int k=1;k<=siteN;k++){
                if(report[j]!=report[k]){
                    times[j]++;
                }
            }
        }
         //ͳ����ϣ��ҳ�����
        int maxTimes= *max_element(times+1,times+siteN+1);


        //ͳ�Ƴ������Ĵ���
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
