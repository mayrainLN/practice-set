#include<bits/stdc++.h>
using namespace std;
class stu{
public:
	string id;
	int C;
	int M;
	int E;
	//ƽ���ɼ� 
	int A;
	//������� 
	int R;
	//��Ŀ 
	char sub; 
}; 

int main()
{
	int n,m;
	stu a[100];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].id>>a[i].C>>a[i].M>>a[i].E;
		a[i].A=(a[i].C+a[i].M+a[i].E)/3; 
	}
	
	//��ÿ��ͬѧ��A����; 
	for(int i=0;i<n;i++)
	{
		//��ÿ��ͬѧ��Að��;
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-j-1;k++)
			{
				if(a[i].A<a[i+1].A){
					stu x=a[i];
					a[i]=a[i+1];
					a[i+1]=x;
				}
			}
		for(int j=0;j<n;j++)
		{
			a[j].R=j;
			a[j].sub='A';
		}
	}
	
	//��ÿ��ͬѧ��C����; 
	for(int i=0;i<n;i++)
	{
		//��ÿ��ͬѧ��Cð��;
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-j-1;k++)
			{
				if(a[i].C<a[i+1].C){
					stu x=a[i];
					a[i]=a[i+1];
					a[i+1]=x;
				}
			}
		for(int j=0;j<n;j++)
		{
			//��ʱi��Ϊa[i]ͬѧ��C�ɼ����� 
			if(j<a[j].R){
				a[j].R=j;
				a[j].sub='C';
			}
		}
	}
	
	//��ÿ��ͬѧ��M����; 
	for(int i=0;i<n;i++)
	{
		//��ÿ��ͬѧ��Mð��;
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-j-1;k++)
			{
				if(a[i].M<a[i+1].M){
					stu x=a[i];
					a[i]=a[i+1];
					a[i+1]=x;
				}
			}
		for(int j=0;j<n;j++)
		{
			//��ʱi��Ϊa[i]ͬѧ��C�ɼ����� 
			if(j<a[j].R){
				a[j].R=j;
				a[j].sub='M';
			}
		}
	}
	
	//��ÿ��ͬѧ��E����; 
	for(int i=0;i<n;i++)
	{
		//��ÿ��ͬѧ��Eð��;
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-j-1;k++)
			{
				if(a[i].E<a[i+1].E){
					stu x=a[i];
					a[i]=a[i+1];
					a[i+1]=x;
				}
			}
		for(int j=0;j<n;j++)
		{
			//��ʱi��Ϊa[i]ͬѧ��C�ɼ����� 
			if(j<a[j].E){
				a[j].R=j;
				a[j].sub='E';
			}
		}
	}
	
	
	
	
	
	string find[100];
	for(int i=0;i<m;i++)
	{
		cin>>find[i];
	}
	
	int max=0,maxi=0;
	//��ÿ��ѧ��id���в��� 
	for(int i=0;i<m;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			//�ҵ���ͬѧ 
			if(a[j].id==find[i])
			{
				cout<<a[j].R<<" "<<a[j].sub<<endl;
				break;
			}
		}
		if(j==n) cout<<"N/A"<<endl;
	}
	
	return 0;
}
