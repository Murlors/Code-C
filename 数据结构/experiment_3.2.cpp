#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef  struct  Node{
    ElementType  data;
    struct Node  *lchild;
    struct Node  *rchild;
}BSTNode, *BSTree;

BSTree insert(BSTree bst, ElementType x);
void inOrder(BSTree bst);
BSTNode* findMin(BSTree bst);
BSTNode* findMax(BSTree bst);
BSTNode* find(BSTree bst, ElementType x);
BSTree deleteNode(BSTree bst, ElementType x);
BSTree destroyBSTree(BSTree bst);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
BSTree insert(BSTree bst, ElementType x) {
    if (bst == NULL) {
        bst = new BSTNode;
        bst->data = x;
        bst->lchild = NULL;
        bst->rchild = NULL;
    } else if (x > bst->data)bst->rchild = insert(bst->rchild, x);
    else if (x < bst->data)bst->lchild = insert(bst->lchild, x);
    return bst;
}
void inOrder(BSTree bst) {
    if (bst != NULL) {
        inOrder(bst->lchild);
        cout << bst->data << " ";
        inOrder(bst->rchild);
    }
}
BSTNode* findMin(BSTree bst) {
    if (bst == NULL) return NULL;
    if (bst->lchild != NULL) return findMin(bst->lchild);
    else return bst;
}
BSTNode* findMax(BSTree bst) {
    if (bst == NULL) return NULL;
    if (bst->rchild != NULL) return findMax(bst->rchild);
    else return bst;
}
BSTNode* find(BSTree bst, ElementType x) {
    if (bst == NULL) return NULL;
    else if (x > bst->data) return find(bst->rchild, x);
    else if (x < bst->data) return find(bst->lchild, x);
    return bst;
}
BSTree deleteNode(BSTree bst, ElementType x) {
    if (bst == NULL) return NULL;
    else if (x > bst->data) bst->rchild = deleteNode(bst->rchild, x);
    else if (x < bst->data) bst->lchild = deleteNode(bst->lchild, x);
    else {
        if (bst->lchild && bst->rchild) {
            BSTree tmp = findMin(bst->rchild);
            bst->data = tmp->data;
            bst->rchild = deleteNode(bst->rchild, tmp->data);
        } else {
            BSTree tmp = bst;
            if (!bst->lchild) bst = bst->rchild;
            else if (!bst->rchild) bst = bst->lchild;
            delete tmp;
        }
    }
    return bst;
}
BSTree destroyBSTree(BSTree bst) {
    if (bst != NULL) {
        destroyBSTree(bst->lchild);
        destroyBSTree(bst->rchild);
        delete bst;
    }
    return NULL;
}