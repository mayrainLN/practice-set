#include<bits/stdc++.h>
using namespace std;
struct Node{
//	到达时间 
	char ari[9];
//	转化成秒的到达时间 
	int sari;
//	等待多少秒 
	int wat;
	Node* next;  
};
typedef Node* List;
Node* tail;

struct peo{
//	转化成秒的到达时间 
	int sari;
//	等待多少秒 
	int wat;
};

int Init(List &L)
{
	//产生头节点并使L指向头结点； 我们可以将L理解为这个链表(队列）的名字 ； 
	L=(Node*)malloc(sizeof(Node));
	L->next=NULL; //头节点指向空 
	tail=L;
	return 0;
}

void Insert(List L,char a[],int w)
{
	tail->next=(Node*)malloc(sizeof(Node));//malloc返回地址
	tail=tail->next;
	tail->next=NULL;
	tail->ari=a;
//	等待秒数 
	tail->wat=w*60;
	int xx=(tail->ari[0]-'0')*36000+(tail->ari[1]-'0')*3600+(tail->ari[3]-'0')*600+(tail->ari[4]-'0')*60+(tail->ari[6]-'0')*10+(tail->ari[7]-'0');
//	到达时间距离8点整的秒数 
	tail->sari=xx-28800;
}

void Delete(List L)
{
//	L指向头节点  L->next指向第一个节点 
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
