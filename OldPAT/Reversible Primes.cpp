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
//进制转换 
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
//	注意这个函数的用法 
// 语法: const char *c_str();
//
//c_str()函数返回一个指向正规C字符串的指针, 内容与本string串相同. 
//
//这是为了与c语言兼容，在c语言中没有string类型，故必须通过string类对象的成员函数c_str()把string 对象转换成c中的字符串样式。
//
//注意:一定要使用strcpy()函数 等来操作方法c_str()返回的指针 
//
//1、比如:最好不要这样: 
//
//char* c;
//
//string s="1234";
//
//c = s.c_str(); //c最后指向的内容是垃圾，因为s对象被析构，所以不能直接利用c_str返回的字符串，要利用strcpy等函数进行复制后再使用
//
//2、其内容被处理应该这样用: 
//
//char c[20];
//
//string s="1234";
//
//strcpy(c,s.c_str()); 
//
//这样才不会出错，c_str()返回的是一个临时指针，不能对其进行操作。
//
//3、再举个例子c_str() 以 char* 形式传回 string 内含字符串如果一个函数要求char*参数，可以使用c_str()方法:
//
//string s = "Hello World!";
//
//printf("%s", s.c_str()); //输出 "Hello World!"
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
	//s=reverse(s.begin(),s.end()); 这样写是错误的，reverse直接改变s，因为传的是地址。返回值大概是指向新s的指针吧 
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
