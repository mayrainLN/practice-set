#include<bits/stdc++.h>
using namespace std;
class stu{
public:
	string id;
	int C;
	int M;
	int E;
	//ƽ���ɼ�
	double A;
	//�������
	int R=99;
	//��Ŀ
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

	//��ÿ��ͬѧ��A����;
	for(int i=0;i<n;i++)
	{
		//��ÿ��ͬѧ��Að��;
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

	//��ÿ��ͬѧ��C����;
	for(int i=0;i<n;i++)
	{
		//��ÿ��ͬѧ��Cð��;
		for(int j=0;j<n-1;j++)
			for(int k=0;k<n-j-1;k++)
			{
				if(a[k].C<a[k+1].C){
					stu x=a[k];
					a[k]=a[k+1];
					a[k+1]=x;
				}
			}
        //����ѧ��
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
			//��ʱi��Ϊa[i]ͬѧ��C�ɼ�����
			if(real<a[j].R){
				a[j].R=real;
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
				if(a[k].M<a[k+1].M){
					stu x=a[k];
					a[k]=a[k+1];
					a[k+1]=x;
				}
			}
		//����ѧ��
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
			//��ʱi��Ϊa[i]ͬѧ��C�ɼ�����
			if(real<a[j].R){
				a[j].R=real;
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
				if(a[k].E<a[k+1].E){
					stu x=a[k];
					a[k]=a[k+1];
					a[k+1]=x;
				}
			}
		//����ѧ��
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
			//��ʱi��Ϊa[i]ͬѧ��C�ɼ�����
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
	//��ÿ��ѧ��id���в���
	for(int i=0;i<m;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			//�ҵ���ͬѧ
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
