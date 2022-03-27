#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTree;

int getDepth(BTree rt);
int getLeafNum(BTree rt);
void leafNode(BTree rt);
int getNum(BTree rt);
void preOrderExt(BTree bt);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
int getDepth(BTree rt) {
    if (rt == NULL) return 0;
    else {
        int dl, dr;
        dl = getDepth(rt->lchild);
        dr = getDepth(rt->rchild);
        return (dl > dr ? dl : dr) + 1;
    }
}
int getLeafNum(BTree rt) {
    if (rt == NULL) return 0;
    else {
        if ((rt->lchild == NULL) && (rt->rchild == NULL)) return 1;
        else return getLeafNum(rt->lchild) + getLeafNum(rt->rchild);
    }
}
void leafNode(BTree rt) {
    if (rt != NULL) {
        if ((rt->lchild == NULL) && (rt->rchild == NULL)) cout << rt->data;
        leafNode(rt->lchild);
        leafNode(rt->rchild);
    }
}
int getNum(BTree rt) {
    if (rt == NULL) return 0;
    else return getNum(rt->lchild) + getNum(rt->rchild)+1;
}
void preOrderExt(BTree bt) {
    if (bt != NULL) {
        cout << bt->data;
        preOrderExt(bt->lchild);
        preOrderExt(bt->rchild);
    } else cout << '.';
}