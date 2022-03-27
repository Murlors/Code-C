#include "bits/stdc++.h"
using namespace std;
typedef int ElementType;
typedef struct Node {
    ElementType data;
    struct Node* lchild;
    struct Node* rchild;
} BSTNode, * BSTree;
BSTree createTree(char s[]);
BSTree insert(BSTree bst, ElementType x);
void printTree(BSTree bst);
char str1[2000000],str2[2000000];
int k=0;
int main() {
    cin >> str2;
    BSTree bst = createTree(str2);
    int n,tmp;
    cin>>n;
    while (n--){
        cin>>tmp;
        insert(bst,tmp);
    }
    printTree(bst);
    str1[k++] = '\0';
    cout<<str1<<endl;
    return 0;
}
BSTree createTree(char s[]) {
    BSTree bst = NULL;
    int l = 0, flag = 0, m = 1;
    for (int i = 0; s[i]; ++i) {
        if (isdigit(s[i])) {
            l = s[i] - '0' + l * 10;
            flag = 1;
        } else if (flag) {
            if (m == 1) {
                bst = insert(bst, l);
                m = 0;
            } else insert(bst, l);
            l = 0;
            flag = 0;
        }
    }
    return bst;
}
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
void printTree(BSTree bst) {
    if (bst != NULL) {
        int tmp = bst->data;
        if (tmp == 0)str1[k++] = '0';
        else {
            int n = tmp, t = 0;
            char it[11];
            while (n != 0) {
                it[t++] = (char) ('0' + n % 10);
                n /= 10;
            }
            for (int i = t - 1; i >= 0; i--) str1[k++] = it[i];
        }
        if (bst->lchild != NULL || bst->rchild != NULL) {
            str1[k++] = '(';
            printTree(bst->lchild);
            str1[k++] = ',';
            printTree(bst->rchild);
            str1[k++] = ')';
        }
    }
}