#include<bits/stdc++.h>
using namespace std;
int main()
{
	string sa,sb;
	int a=0,b=0,tag,radix;
	cin>>sa>>sb>>tag>>radix;
	if(tag==1)
	{
		for(int i=0;i<sa.size();i++)
		{
			//ÃÝ 
			int p=sa.size()-1-i; 
			//×ÖÄ¸ 
			if(sa[i]<'0'||sa[i]>'9'){
				a+=pow(radix,p)*((sa[i]-'a')+10);
			}							
		
			else{
				a+=pow(radix,p)*(sa[i]+0);
			}
		}
		
		//r ½øÖÆ 
		int r;
		for(r=2;b<a;r++)
		{
			b=0;
			for(int i=0;i<sb.size();i++)
			{
			//ÃÝ 
			int p=sb.size()-1-i; 
			//×ÖÄ¸ 
			if(sb[i]<'0'||sb[i]>'9'){
				b+=pow(r,p)*((sb[i]-'a')+10);
			}							
		
			else{
				a+=pow(r,p)*(sb[i]+0);
			}
			}			
		}
		
		if(b==a)
			cout<<r;
		else
			cout<<"Impossible";
		
	}
	else if(tag==2)
	{
		for(int i=0;i<sb.size();i++)
		{
			//ÃÝ 
			int p=sb.size()-1-i;
			//×ÖÄ¸ 
			if(sb[i]<'0'||sb[i]>'9'){
				 b+=pow(radix,p)*((sb[i]-'a')+10);
			}							
		
			else{
				b+=pow(radix,p)*(sb[i]+0);
			}
		}
		
		//r ½øÖÆ 
		int r;
		for(r=2;a<b;r++)
		{
			a=0;
			for(int i=0;i<sa.size();i++)
			{
			//ÃÝ 
			int p=sa.size()-1-i; 
			//×ÖÄ¸ 
			if(sa[i]<'0'||sa[i]>'9'){
				a+=pow(r,p)*((sa[i]-'a')+10);
			}							
		
			else{
				a+=pow(r,p)*(sa[i]+0);
			}
			}			
		}
		
		if(b==a)
			cout<<r;
		else
			cout<<"Impossible";
			
	}
 } 
