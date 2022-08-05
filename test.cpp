#include"bits/stdc++.h"
using namespace std;

typedef struct Node {
    int data, layer;
    struct Node *l = NULL, *r = NULL;
} Node;
vector<int> pre, in, ans;

Node* create (int pre1, int pre2, int in1, int in2) {
    //没有根了
    if (pre1 > pre2) return NULL;
    int i = in1;
    //找到根在中序序列中的位置
    while (in[i] != pre[pre1]) i++;
    //左子树的元素个数
    int len = i - in1;
    Node* node = new Node;
    //写入根
    node->data = pre[pre1];
    //往左子树递归 l指向左子树的地址
    node->l = create(pre1 + 1, pre1 + len, in1, i - 1);
    node->r = create(pre1 + len + 1, pre2, i + 1, in2);
    // 返回当前(根)的地址
    return node;
}
int main(){
    
    return 0;
}