#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[10001];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
//	for(int i=0;i<1000;i++)
//	{
//		cout<<a[i]<<endl;
//	}
	int i=0,j=0,F=a[0],L=a[n-1],sum=0,cur_sum;
	while(i<=n-1)
	{
		if(a[i]>0)
		{
			cur_sum=a[i];//此时cur_sum必大于0； 
			for(j=i;cur_sum>0&&j<n;j++)
			{
				if(j!=i)
				cur_sum+=a[j];
				if(cur_sum>sum)
				{
					F=a[i];
					L=a[j];
					sum=cur_sum;
				}
			}
		}
		if(a[i]==0&&sum==0)
		{
			F=a[i];L=a[i];
		}
		
		i++;
	}
	cout<<sum<<' '<<F<<' '<<L;
	return 0;
 } 
