#include<bits/stdc++.h>
using namespace std;
struct Node{
//	����ʱ�� 
	char ari[9];
//	ת������ĵ���ʱ�� 
	int sari;
//	�ȴ������� 
	int wat;
	Node* next;  
};
typedef Node* List;
Node* tail;

struct peo{
//	ת������ĵ���ʱ�� 
	int sari;
//	�ȴ������� 
	int wat;
};

int Init(List &L)
{
	//����ͷ�ڵ㲢ʹLָ��ͷ��㣻 ���ǿ��Խ�L���Ϊ�������(���У������� �� 
	L=(Node*)malloc(sizeof(Node));
	L->next=NULL; //ͷ�ڵ�ָ��� 
	tail=L;
	return 0;
}

void Insert(List L,char a[],int w)
{
	tail->next=(Node*)malloc(sizeof(Node));//malloc���ص�ַ
	tail=tail->next;
	tail->next=NULL;
	tail->ari=a;
//	�ȴ����� 
	tail->wat=w*60;
	int xx=(tail->ari[0]-'0')*36000+(tail->ari[1]-'0')*3600+(tail->ari[3]-'0')*600+(tail->ari[4]-'0')*60+(tail->ari[6]-'0')*10+(tail->ari[7]-'0');
//	����ʱ�����8���������� 
	tail->sari=xx-28800;
}

void Delete(List L)
{
//	Lָ��ͷ�ڵ�  L->nextָ���һ���ڵ� 
	L->next=L->next->next; 
}

int main()
{
	int n,w;
	cin>>n>>w;
	peo peos[1000];
	char s[9];
	for(int i=0;i<n;i++)
	{
		scanf("%s",s)
	}
	List L;
	Init(L); 
}
