#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
	cin>>a>>b; 
	c=a+b; 
	string sum=to_string(c);
	int i=0,j=sum.size()-1;
	string newSum="";
	while(j>=0&&sum[j]!='-')
	{
		newSum=sum[j]+newSum;
		i++;
		if(i%3==0&&j!=0&&sum[j-1]!='-')
		{
			newSum=','+newSum;
		} 
		j--;
	 }
	 if(sum[0]=='-')
	 	newSum='-'+newSum;
	cout<<newSum;
	return 0;
}

