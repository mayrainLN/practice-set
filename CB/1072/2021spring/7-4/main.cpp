#include"bits/stdc++.h"
using namespace std;
//key要堆排序，所以按照key排序，最小的一定是树的根。这样就有了根的信息
//pri从小到大排，就是中序 确定根后，可以划分左右子树，再从左右子树中，选择根

//其实和 根据先序、中序建树 是一样的

//根据先序序列和中序序列建树；
BiTree CreateBitreeByPreOrderMidOrder(string PreS, string MidS)
{
    //如果(子)树的先序序列为0，说明(子)树为空。返回NULL;
    if (PreS.size() == 0)
        return NULL;
    //(子)树的根一定为先序序列的第一个
    ElemType rootValue = PreS[0];
    //创建(子)树的根节点，赋值
    BiTree root = (BiTree)malloc(sizeof(BiTree));
    root->data = rootValue;
    //获取根节点在中序序列的位置，即可确定左右子树的先序和后序；
    int index = MidS.find(rootValue);

    string LeftPreS = PreS.substr(1, index);
    string RightPreS = PreS.substr(1 + index);
    string LeftMidS = MidS.substr(0, index);
    string RightMidS = MidS.substr(1 + index);

    root->LChild = CreateBitreeByPreOrderMidOrder(LeftPreS, LeftMidS);
    root->RChild = CreateBitreeByPreOrderMidOrder(RightPreS, RightMidS);

    return root;
}


int main(){

    return 0;
}
