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
	double c[2002],z,x; //,����������c�����У�c�Ǳ꼴Ϊָ����z��x�ֱ�Ϊ�����ָ����ϵ���� 
	
	for(int i=0;i<2002;i++)
	{
		c[i]=0;
	}
	for(int i=0;i<n2;i++)
	{
		cin>>z>>x;
		//ÿ����һ�Σ�����һ������ʽ���һ�Ρ�  
		for(int j=0;j<n1;j++)
		{
			//a[j][0]+zΪ��ָ��   a[j][1]*xΪ�˳�����һ���ϵ����Ȼ��ǵúϲ�����ʽ 
			 c[(int)(a[j][0]+z)]=a[j][1]*x+c[(int)(a[j][0]+z)];
		}
	} 
	
	int sum=0;//index�������ϵ����Ϊ����ݡ���Ҫ�����c�ĽǱ�;
	for(int i=0;i<2002;i++)
	{
		//ϵ����Ϊ�㣻c[3]!=0�� x�����η�  ϵ����Ϊ��  
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
