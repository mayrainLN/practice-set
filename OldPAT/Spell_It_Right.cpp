#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,_s;
	cin>>s; 
	int n=s.size(),sum=0;
	for(int i=0;i<n;i++)
	{
		//'0'的阿斯克码是48 
		sum=sum+(s[i]-48);
	}
	_s=to_string(sum);
	int _n=_s.size();
	switch(_s[0])
		{
			case '0':
				cout<<"zero"; break;
			case '1':
				cout<<"one"; break;
			case '2':
				cout<<"two"; break;
			case '3':
				cout<<"three"; break;
			case '4':
				cout<<"four"; break;
			case '5':
				cout<<"five"; break;
			case '6':
				cout<<"six"; break;
			case '7':
				cout<<"seven"; break;
			case '8':
				cout<<"eight"; break;
			case '9':
				cout<<"nine"; break;
		}
	for(int i=1;i<_n;i++)
	{
		switch(_s[i])
		{
			case '0':
				cout<<" zero"; break;
			case '1':
				cout<<" one"; break;
			case '2':
				cout<<" two"; break;
			case '3':
				cout<<" three"; break;
			case '4':
				cout<<" four"; break;
			case '5':
				cout<<" five"; break;
			case '6':
				cout<<" six"; break;
			case '7':
				cout<<" seven"; break;
			case '8':
				cout<<" eight"; break;
			case '9':
				cout<<" nine"; break;
		}
	}
}
