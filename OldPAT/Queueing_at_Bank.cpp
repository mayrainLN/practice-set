#include<bits/stdc++.h>
using namespace std;
//需要维护的是服务窗口，用一个“优先队列”进行维护。里面存放的是“本窗口空闲的时刻” 

//后面排队的人，不需要维护，只需要用结构体数组存储，按照到达时间排个序，一个一个往后读

//算法： 存储三个窗口的“优先队列”，初始化存入三个8.00, 接着遍历后面排队的人。
//若到达时刻>=窗口空闲时刻 （即优先队列的队首，最早空闲的窗口）
//=>此人无需等待，total不变；pop队首，push（此人到达时间+服务时间） 
//若到达时刻<窗口空闲时刻 
//=>total+=窗口空闲时刻-到达时刻；push(窗口空闲时刻+服务时间)

//好像普通队列也行，就是始终要维护队列大小顺序。貌似优先队列可以自动维护  

//后面排队的人； 
struct peo{
	//没必要时分秒都写进去，输出与其无关。写得多看的烦，输入的时候转化一下就行。 
	//到达秒数 
	int ari;
	//等待秒数 
	int wat;
};

bool cmp(peo a,peo b)
{
	return a.ari<b.ari;
}

int main()
{
	//人数 窗口数
	int np,nw;
	//优先队列(升序)，具体使用看收藏夹； 
	priority_queue< int,vector<int>,greater<int> > q;
	
	//排队的人 
	peo p[10001];
	cin>>np>>nw;
	//由于17.00之后到达的人无需排队直接走人，因此，如果将他们存入p数组中，排序就会带来问题。
	//np记录的是总人数，npp记录的是有效人数。 
	int npp=np;
	for(int i=0;i<npp;)
	{
		int h,m,s,w;
		scanf("%d:%d:%d %d",&h,&m,&s,&w);
		if(3600*h+60*m+s>61200) 
		{
			//超过17.00，有效人数--； 
			npp--;
			continue;
		}
		p[i].ari=3600*h+60*m+s;
		p[i].wat=60*w;
		i++;
		//cout<<p[i].ari<<"   "<<p[i].wat;
	}
	//sort默认从小到大排序；
	//cmp返回为真，则顺序不变，否则交换。->return a>b 降序 
	//如果我们想从大到小排序可以将cmp参数写为greater<int>()就是对int数组进行排序   
	sort(p,p+npp,cmp);
	
//	for(int i=0;i<npp;i++){
//		cout<<p[i].ari<<"  "<<p[i].wat<<endl;
//	}
	
	//初始化窗口，初值为8.00
	for(int i=0;i<nw;i++)
	{
		q.push(28800);
	}
	
	//算法
	int total=0;
	for(int i=0;i<npp;i++)
	{
		//ww为 最先闲置出来的窗口的 闲置时刻 
		int ww=q.top();
		q.pop();
		//到达时间早于闲置时刻 
		if(p[i].ari<ww){
			total+=ww-p[i].ari;
			q.push(ww+p[i].wat);
		}
		//到达时间晚于或等于空闲时刻，则无需等待
		else{
			q.push(p[i].ari+p[i].wat); 
		} 
	} 
	printf("%.1f",total/60.0/npp);
}
 



