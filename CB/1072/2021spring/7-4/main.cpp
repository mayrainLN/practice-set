#include"bits/stdc++.h"
using namespace std;
//keyҪ���������԰���key������С��һ�������ĸ������������˸�����Ϣ
//pri��С�����ţ��������� ȷ�����󣬿��Ի��������������ٴ����������У�ѡ���

//��ʵ�� �������������� ��һ����

//�����������к��������н�����
BiTree CreateBitreeByPreOrderMidOrder(string PreS, string MidS)
{
    //���(��)������������Ϊ0��˵��(��)��Ϊ�ա�����NULL;
    if (PreS.size() == 0)
        return NULL;
    //(��)���ĸ�һ��Ϊ�������еĵ�һ��
    ElemType rootValue = PreS[0];
    //����(��)���ĸ��ڵ㣬��ֵ
    BiTree root = (BiTree)malloc(sizeof(BiTree));
    root->data = rootValue;
    //��ȡ���ڵ����������е�λ�ã�����ȷ����������������ͺ���
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
