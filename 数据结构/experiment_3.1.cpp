#include<bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *lchild;
    struct Node *rchild;
}BTNode,*BTree;

BTree createTree(char s[]);
void preOrder(BTree root);
void inOrder(BTree rt);
void postOrder(BTree rt);
void layerOrder(BTree rt);
void printTree(BTree bt);
BTree createTree(char s[],int left,int right);
void destroyTree(BTree bt);
int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/

//由字符串s创建一颗二叉树 其中字符串s是仅由‘(’、‘)’、‘,’以及大小写字符构成的二叉树的广义表表示
BTree createTree(char s[]) {
    BTree tree[strlen(s) + 1], p;
    int flag = 0, parent = 0;
    for (int i = 0; s[i]; ++i) {
        if (isalpha(s[i])) {
            p = new BTNode;
            p->data = s[i];
            p->lchild = NULL;
            p->rchild = NULL;
            if (flag == -1)
                tree[parent]->lchild = p;
            else if (flag == 1)
                tree[parent]->rchild = p;
        } else if (s[i] == '(') {
            tree[++parent] = p;
            flag = -1;
        } else if (s[i] == ')') {
            parent--;
        } else if (s[i] == ',') {
            flag = 1;
        }
    }
    if (strlen(s) == 1) tree[++parent] = p;
    return tree[1];
}
void preOrder(BTree root) {
    if (root != NULL) {
        cout << root->data;
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}
void inOrder(BTree rt) {
    if (rt != NULL) {
        inOrder(rt->lchild);
        cout << rt->data;
        inOrder(rt->rchild);
    }
}
void postOrder(BTree rt) {
    if (rt != NULL) {
        postOrder(rt->lchild);
        postOrder(rt->rchild);
        cout << rt->data;
    }
}
void layerOrder(BTree rt) {
    queue<BTree> Q;
    BTree p;
    Q.push(rt);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        cout << p->data;
        if (p->lchild != NULL)Q.push(p->lchild);
        if (p->rchild != NULL)Q.push(p->rchild);
    }
}
void printTree(BTree bt) {
    if (bt != NULL) {
        cout << bt->data;
        if (bt->lchild != NULL || bt->rchild != NULL) {
            cout << '(';
            printTree(bt->lchild);
            cout << ',';
            printTree(bt->rchild);
            cout << ')';
        }
    }
}
int find(char s[],int left,int right) {
    int k = 0, i;
    for (i = left; i <= right; i++) {
        if (s[i] == ',' && k == 1)return i;
        if (s[i] == '(')k++;
        else if (s[i] == ')')k--;
    }
    return left;
}
BTree newnode(ElementType x) {
    BTree p = new BTNode;
    p->data = x;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}
BTree createTree(char s[],int left,int right) {
    int mid;
    if (left > right) return NULL;
    BTree p = newnode(s[left]);
    mid = find(s, left, right);
    p->lchild = createTree(s, left + 2, mid - 1);
    p->rchild = createTree(s, mid + 1, right - 1);
    return p;
}
void destroyTree(BTree bt) {
    if (bt == NULL)return;
    stack<BTree> S;
    S.push(bt);
    while (!S.empty()) {
        bt = S.top();
        S.pop();
        if (bt->lchild != NULL)S.push(bt->lchild);
        if (bt->rchild != NULL)S.push(bt->rchild);
        delete bt;
    }
}