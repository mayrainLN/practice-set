#include<bits/stdc++.h>
using namespace std;
//真是蠢死我了。c++明明可以直接比较字符串 
int cmp(string a,string b)
{
	if(a[0]<b[0]) return 0;
	  else if(a[0]>b[0]) return 1; 
		else if(a[1]<b[1]) return 0;
		else if(a[1]>b[1]) return 1; 
			else if(a[3]<b[3]) return 0;
			else if(a[3]>b[3]) return 1; 
				else if(a[4]<b[4]) return 0;
				else if(a[4]>b[4]) return 1; 
					else if(a[6]<b[6]) return 0;
					else if(a[6]>b[6]) return 1; 
						else if(a[7]<b[7]) return 0;
						else if(a[7]>b[7]) return 1; 
							else return 0;
}
int main()
{
	int n;
	char s[900][3][16];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i][0];
		cin>>s[i][1];
		cin>>s[i][2];
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<s[i][0]<<endl;
//		cout<<s[i][1]<<endl;
//		cout<<s[i][2]<<endl;
//	}

	string lat=s[0][2],ear=s[0][1],lat_id=s[0][0],ear_id=s[0][0];
	for(int i=0;i<n;i++)
	{
		//前数组大于后数字，返回1 
		if(ear>s[i][1])
			ear_id=s[i][0];
		if(s[i][2]>lat)
			lat_id=s[i][0]; 
	}
	cout<<ear_id<<" "<<lat_id;

//	cout<<cmp(s[0][1],s[1][1]); 
	return 0;
 } 
