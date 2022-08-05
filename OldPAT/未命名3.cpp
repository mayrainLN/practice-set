#include<cstdio>
#include<iostream>
using namespace std; 

int IsPrime(int n){//是质数则返回1,否则返回0
    if(n==1) return 0;//1不是质数
	if(n==2) return 1;//2是质数
	for(int i=2;i<n/2;i++)
		if(n%i==0) return 0;//有其他约数则非质数
	return 1;//否则是质数
}

int main()
{
    int N, D;
    while(1){
        cin>>N;
        if(N<0) break;
        cin>>D;
        int flag1 = IsPrime(N);//flag1标志N本身是否为质数
        int numd=0, power=1, num[100], x=0;
        //numd为N在D进制下的逆转,power为某一位代表的数量级,num暂存N转化成D进制数的倒序,x为N转化为D进制后的位数
        while(N){//N转化为D进制
            num[x++] = N % D;
            N /= D;
        }
        for(int i=x-1;i>=0;i--){//num首位为N的末位,即其逆转的首位,则从num末位即N逆转的首位起计算
            numd += num[i]*power;
            power *= D;
        }
        int flag2 = IsPrime(numd);//flag2标志其逆转是否为质数
        if(flag1&&flag2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

