using namespace std;
#include<bits/stdc++.h>
int main()
{
	int n1,n2;
	double a[10][2],b[10][2];
	cin>>n1;
	for(int i=0;i<n1;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	
	cin>>n2;
	double c[2002],z,x; //,计算结果存入c数组中，c角标即为指数。z，x分别为输入的指数和系数。 
	
	for(int i=0;i<2002;i++)
	{
		c[i]=0;
	}
	for(int i=0;i<n2;i++)
	{
		cin>>z>>x;
		//每输入一次，往第一个多项式里乘一次。  
		for(int j=0;j<n1;j++)
		{
			//a[j][0]+z为新指数   a[j][1]*x为乘出来的一项的系数，然后记得合并多项式 
			 c[(int)(a[j][0]+z)]=a[j][1]*x+c[(int)(a[j][0]+z)];
		}
	} 
	
	int sum=0;//index数组存入系数不为零的幂。即要输出的c的角标;
	for(int i=0;i<2002;i++)
	{
		//系数不为零；c[3]!=0即 x的三次方  系数不为零  
		if(c[i]!=0) 
		{
			sum++; 	
		}
	}
	
	cout<<sum;
	
	for(int i=2001;i>=0;i--)
	{
		if(c[i]!=0)
		printf(" %d %.1f",i,c[i]); 
	}
		
	return 0; 
 } 
