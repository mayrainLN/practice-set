#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a[3][3],s=1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			cin>>a[i][j];
	}
	for(int i=0;i<3;i++)
	{
		double max=0;int maxi;
		for(int j=0;j<3;j++){
			if(a[i][j]>max) {
				max=a[i][j];
				maxi=j;
			}
		}
		if(maxi==0) cout<<"W ";
		else if(maxi==1) cout<<"T ";
		else cout<<"L ";
		s=s*max;
	}
	printf("%.2f",2*(s*0.65-1));
	return 0;
 } 
