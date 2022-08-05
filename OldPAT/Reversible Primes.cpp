#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x)
{
	for(int i=2;i<=sqrt(x);i++)
		{
			if(x%2==0) return false;
		}
	return true;
}
//����ת�� 
int tran(int x,int d)
{
	int xx=0;
	if(d==10)
	return x;
	if(d==1){
		
		for(int i=0;i<x;i++)
		{
			xx=xx*10+1;
		}
		return xx;
	}
	
	string s;
	while(x)
	{
		s=to_string(x%d)+s;
		x/=d;
	}
	return atoi(s.c_str());
//	ע������������÷� 
// �﷨: const char *c_str();
//
//c_str()��������һ��ָ������C�ַ�����ָ��, �����뱾string����ͬ. 
//
//����Ϊ����c���Լ��ݣ���c������û��string���ͣ��ʱ���ͨ��string�����ĳ�Ա����c_str()��string ����ת����c�е��ַ�����ʽ��
//
//ע��:һ��Ҫʹ��strcpy()���� ������������c_str()���ص�ָ�� 
//
//1������:��ò�Ҫ����: 
//
//char* c;
//
//string s="1234";
//
//c = s.c_str(); //c���ָ�����������������Ϊs�������������Բ���ֱ������c_str���ص��ַ�����Ҫ����strcpy�Ⱥ������и��ƺ���ʹ��
//
//2�������ݱ�����Ӧ��������: 
//
//char c[20];
//
//string s="1234";
//
//strcpy(c,s.c_str()); 
//
//�����Ų������c_str()���ص���һ����ʱָ�룬���ܶ�����в�����
//
//3���پٸ�����c_str() �� char* ��ʽ���� string �ں��ַ������һ������Ҫ��char*����������ʹ��c_str()����:
//
//string s = "Hello World!";
//
//printf("%s", s.c_str()); //��� "Hello World!"
}

int reTran(int x,int radix)
{
	int xx=0,power=0;
	if(radix==10)
		return x;
	while(x)
	{
		xx+=(x%10)*pow(radix,power);
		power++;
		x/=10;
	}
	return xx;
}
int myReverse(int x)
{
	string s=to_string(x);
	//s=reverse(s.begin(),s.end()); ����д�Ǵ���ģ�reverseֱ�Ӹı�s����Ϊ�����ǵ�ַ������ֵ�����ָ����s��ָ��� 
	reverse(s.begin(),s.end()); 
	return atoi(s.c_str());
}
int main()
{
	int a,radix;
//	cout<<tran(3,1);
	while(1)
	{		
		int flag=0;
		cin>>a;
		if(a<=0) break;
		cin>>radix;
		if(radix<=0) break;
		if(isPrime(a)) 
			flag++;
		int newA=reTran((myReverse(tran(a,radix))),radix);
		if(isPrime(newA))
			flag++;
		if(flag==2)
			cout<<"Yes"<<endl;
		else 
			cout<<"No"<<endl;
	}
	return 0; 
}
