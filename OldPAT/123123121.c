#include<stdio.h>
int main()
{
    int i,x,a[101],h=0;
    scanf("%d",&x);
    for(i=0;i<101;i++){
        if(i<x)
            scanf("%d",a[i]);
        else
            a[i]=0;
    }
    for(i=0;a[i+1]!=0;i++){
        if(a[i]<a[i+1])
            h+=6*(a[i+1]-a[i]);
        else
            h+=4*a[i]-a[i+1];
        h+=5;
    }
    printf("%d",h);
}

