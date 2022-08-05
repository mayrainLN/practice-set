#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	cout<<'#';
	int x;
	for(int i=0;i<3;i++)
	{
		int x=a[i]/13;
		switch(x)
		{
			case 0:cout<<'0';break;
			case 1:cout<<'1';break;
			case 2:cout<<'2';break;
			case 3:cout<<'3';break;
			case 4:cout<<'4';break;
			case 5:cout<<'5';break;
			case 6:cout<<'6';break;
			case 7:cout<<'7';break;
			case 8:cout<<'8';break;
			case 9:cout<<'9';break;
			case 10:cout<<'A';break;
			case 11:cout<<'B';break;
			case 12:cout<<'C';break;
			default :break;
		}
		switch(a[i]%13)
		{
			case 0:cout<<'0';break;
			case 1:cout<<'1';break;
			case 2:cout<<'2';break;
			case 3:cout<<'3';break;
			case 4:cout<<'4';break;
			case 5:cout<<'5';break;
			case 6:cout<<'6';break;
			case 7:cout<<'7';break;
			case 8:cout<<'8';break;
			case 9:cout<<'9';break;
			case 10:cout<<'A';break;
			case 11:cout<<'B';break;
			case 12:cout<<'C';break;
			default :break;
		}
	}
	
	return 0;
 } 
