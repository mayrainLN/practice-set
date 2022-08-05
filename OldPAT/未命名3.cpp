#include<cstdio>
#include<iostream>
using namespace std; 

int IsPrime(int n){//�������򷵻�1,���򷵻�0
    if(n==1) return 0;//1��������
	if(n==2) return 1;//2������
	for(int i=2;i<n/2;i++)
		if(n%i==0) return 0;//������Լ���������
	return 1;//����������
}

int main()
{
    int N, D;
    while(1){
        cin>>N;
        if(N<0) break;
        cin>>D;
        int flag1 = IsPrime(N);//flag1��־N�����Ƿ�Ϊ����
        int numd=0, power=1, num[100], x=0;
        //numdΪN��D�����µ���ת,powerΪĳһλ�����������,num�ݴ�Nת����D�������ĵ���,xΪNת��ΪD���ƺ��λ��
        while(N){//Nת��ΪD����
            num[x++] = N % D;
            N /= D;
        }
        for(int i=x-1;i>=0;i--){//num��λΪN��ĩλ,������ת����λ,���numĩλ��N��ת����λ�����
            numd += num[i]*power;
            power *= D;
        }
        int flag2 = IsPrime(numd);//flag2��־����ת�Ƿ�Ϊ����
        if(flag1&&flag2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}

