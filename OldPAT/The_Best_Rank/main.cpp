#include<bits/stdc++.h>
using namespace std;
class stu{
public:
	string id;
	int C;
	int M;
	int E;
	//平均成绩
	double A;
	//最好排名
	int R=99;
	//科目
	char sub;
};

int main()
{
	int n,m;
	stu a[1000];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].id>>a[i].C>>a[i].M>>a[i].E;
		a[i].A=(a[i].C+a[i].M+a[i].E)/3.0;
	}

	//给每个同学的A排名;
	for(int i=0;i<n;i++)
	{
		//对每个同学的A冒泡;
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-j-1;k++)
			{
				if(a[k].A<a[k+1].A){
					stu x=a[k];
					a[k]=a[k+1];
					a[k+1]=x;
				}
			}
		for(int j=0;j<n;j++)
		{
			a[j].R=j;
			a[j].sub='A';
		}
	}

	//给每个同学的C排名;
	for(int i=0;i<n;i++)
	{
		//对每个同学的C冒泡;
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-j-1;k++)
			{
				if(a[k].C<a[k+1].C){
					stu x=a[k];
					a[k]=a[k+1];
					a[k+1]=x;
				}
			}
        //遍历学生
		for(int j=0;j<n;j++)
		{
		    int real;
		    for(int k=0;k<n;k++)
            {
                if(!(a[k].C>a[j].C))
                {
                    real=k;
                    break;
                }
            }
			//此时i即为a[i]同学的C成绩排名
			if(real<a[j].R){
				a[j].R=real;
				a[j].sub='C';
			}
		}
	}

	//给每个同学的M排名;
	for(int i=0;i<n;i++)
	{
		//对每个同学的M冒泡;
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-j-1;k++)
			{
				if(a[k].M<a[k+1].M){
					stu x=a[k];
					a[k]=a[k+1];
					a[k+1]=x;
				}
			}
		//遍历学生
		for(int j=0;j<n;j++)
		{
		    int real;
		    for(int k=0;k<n;k++)
            {
                if(!(a[k].M>a[j].M))
                {
                    real=k;
                    break;
                }
            }
			//此时i即为a[i]同学的C成绩排名
			if(real<a[j].R){
				a[j].R=real;
				a[j].sub='M';
			}
		}
	}

	//给每个同学的E排名;
	for(int i=0;i<n;i++)
	{
		//对每个同学的E冒泡;
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-j-1;k++)
			{
				if(a[k].E<a[k+1].E){
					stu x=a[k];
					a[k]=a[k+1];
					a[k+1]=x;
				}
			}
		//遍历学生
		for(int j=0;j<n;j++)
		{
		    int real;
		    for(int k=0;k<n;k++)
            {
                if(!(a[k].E>a[j].E))
                {
                    real=k;
                    break;
                }
            }
			//此时i即为a[i]同学的C成绩排名
			if(real<a[j].R){
				a[j].R=real;
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
	//对每个学生id进行查找
	for(int i=0;i<m;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			//找到该同学
			if(a[j].id==find[i])
			{
				cout<<a[j].R+1<<" "<<a[j].sub<<endl;
				break;
			}
		}
		if(j==n) cout<<"N/A"<<endl;
	}

	return 0;
}
