#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n1,n2;
	double a[101][2],b[101][2];
	cin>>n1;
	for(int i=0;i<n1;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	
	cin>>n2;
	for(int i=0;i<n2;i++)
	{
		cin>>b[i][0]>>b[i][1];
	}
	
//	int n3=n1+n2,K=0;
//	double c[20][2];
//	for(int i=0;i<n1;i++)
//	{
//		for(int j=0;j<n2;j++)
//		{
//			if(a[i][0]==a[j][0])
//			{
//				c[k][0]==a[i][0]; 
//			}
//		} 
//	}

	double c[20][2];
	int i=0,j=0,n3=n1+n2,k=0;;
	while(i<n1&&j<n2)
	{
		while(a[i][0]>b[j][0])
		{
			c[k][0]=a[i][0];
			c[k][1]=a[i][1];
			i++;
			k++;
		}
		
		while(b[j][0]>a[i][0])
		{
			c[k][0]=b[j][0];
			c[k][1]=b[j][1];
			j++;
			k++;
		}
		
		if(b[j][0]==a[i][0])
		{
			c[k][0]=a[i][0];
			if(a[i][1]+b[j][1]!=0)
			{
				c[k][1]=a[i][1]+b[j][1];k++;
			}
				
			i++;
			j++;
			
		}
	}
	while(i<n1)
	{
		c[k][0]=a[i][0];
		c[k][1]=a[i][1];
		i++;
		k++;
	}
	while(j<n2)
	{
		c[k][0]=b[j][0];
		c[k][1]=b[j][1];
		j++;
		k++;
	}
	
	
	cout<<k;
	for(int i=0;i<k;i++)
	{
		printf(" %.0f %.1f",c[i][0],c[i][1]);
	}
	return 0; 
 } 
