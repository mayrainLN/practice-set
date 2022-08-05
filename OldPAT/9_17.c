#include<stdio.h>
int main()
{
    int x,a[101]={0},h=0;
    scanf("%d",&x);
    for(int i=1;i<101;i++){
        if(i<=x)
            scanf("%d",&a[i]);
        else
            a[i]=0;
    }
    for(int i=0;i<x;i++){
        if(a[i]<a[i+1])
            h+=6*(a[i+1]-a[i]);
        else
            h+=4*(a[i]-a[i+1]);
        h+=5;
    }
    printf("%d",h);
}
