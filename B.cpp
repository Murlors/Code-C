#include <bits/stdc++.h>
using namespace std;
typedef char ElementType;
typedef struct BiTree{
    ElementType data;
    struct BiTree *lchild;
    struct BiTree *rchild;
}*BTree;
int Search_Num(ElementType num,ElementType *array,int len) {
    for (int i = 0; i < len; i++)if (array[i] == num)return i;
}
BTree Resume_BiTree(ElementType *front,ElementType *center,int len) {
    if (len <= 0) return NULL;
    BTree temp = new BiTree;
    temp->data = *front;
    int index = Search_Num(*front, center, len);
    temp->lchild = Resume_BiTree(front + 1, center, index);
    temp->rchild = Resume_BiTree(front + index + 1, center + index + 1, len - index - 1);
    return temp;
}
void PostOrderTraverse(BTree root){
    if (root != NULL) {
        PostOrderTraverse(root->lchild);
        PostOrderTraverse(root->rchild);
        cout << root->data;
    }
}
int main() {
    ElementType* preorder = new ElementType[200];
    ElementType* inorder = new ElementType[200];
    cin >> preorder;
    cin >> inorder;
    BiTree* root = Resume_BiTree(preorder, inorder, strlen(inorder));
    PostOrderTraverse(root);
    cout << endl;
    return 0;
}