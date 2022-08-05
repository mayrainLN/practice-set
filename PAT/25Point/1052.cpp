    #include"bits/stdc++.h"
    using namespace std;
    const int INF=1000000000;
    const int maxn=100005;
    typedef struct node
    {
        int add=-1;
        int data=INF;
        int next=-1;
        bool flag=false;
    }node;

    bool cmp(node a,node b){
        if(a.flag==false||b.flag==false){
            return a.flag>b.flag;
        }
        else return a.data<b.data;
    }

    int main(){
        int n,start,num;
        node list[maxn];
        for(int i=0;i<maxn;i++){
            list[i].flag=false;
        }
        int flag[maxn]={-1};
        cin>>n>>start;
        for(int i=0;i<n;i++){
            int add,data,next;
            cin>>add;
            cin>>list[add].data>>list[add].next;
            list[add].add=add;
        }

        // 走一遍链表，得到链表中的节点数目num；
        for(int i=start;i!=-1;i=list[i].next){
            list[i].flag=true;
            num++;
        }

        sort(list,list+maxn,[](node x,node y)->bool{
            // 两个节点其中有一个为false，将false放置在后面
            if(x.flag==false||y.flag==false){

                // return x.flag!=false;
                return x.flag>y.flag;
            }
            else{
                return x.data<y.data;
            }
        });

        // sort(list,list+maxn,cmp);

        if(num==0){
            cout<<0<<" "<<"-1";
            return 0;
        }
        printf("%d %05d\n",num,list[0].add);
        for (int i = 0; i < num-1; i++)
        {
            list[i].next=list[i+1].add;
            printf("%05d %d %05d\n",list[i].add,list[i].data,list[i].next);
        }    
        printf("%05d %d -1\n",list[num-1].add,list[num-1].data);
        return 0;
    }