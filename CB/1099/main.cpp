#include"bits/stdc++.h"
using namespace std;

vector<int> indexOrder;
typedef struct node{
    int id=-1;
	int l=-1;
	int r=-1;
};

node nodeList[101];
void inOrder(int cur){
    if(nodeList[cur].l>0){
        inOrder(nodeList[cur].l);
        return;
    }
    indexOrder.push_back(nodeList[cur].id);
    if(nodeList[cur].r>0){
        inOrder(nodeList[cur].r);
        return;
    }

}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
        nodeList[i].id=i;
		cin>>nodeList[i].l>>nodeList[i].r;
	}
    inOrder(0);
    for(auto& i:indexOrder){
        cout<<i;
    }
    cout<<"xxx";
    return 0;
}
