#include <bits/stdc++.h>
using namespace std;

typedef char ElementType;
typedef struct CSNode{
    ElementType data;
    struct CSNode * child;
    struct CSNode * sibling;
}CSTNode,*CSTree;

CSTree createTree(char s[]);
CSTree createTree();
void preOrder(CSTree root);
void postOrder(CSTree root);
int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    /*
    char s[200];
    cin >>s;
    CSTree root= createTree(s);*/
    CSTree root= createTree();
    preOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
CSTree createTree(char s[]) {
    CSTree tree[100], tree_sibling[100], p;
    int flag = 0, parent = 0, k = 0;
    for (int i = 0; s[i]; ++i) {
        if (isalpha(s[i])) {
            p = new CSTNode;
            p->data = s[i];
            p->child = NULL;
            p->sibling = NULL;
            if (flag == -1) {
                tree[parent]->child = p;
                tree_sibling[k] = p;
            } else if (flag == 1) {
                tree_sibling[k]->sibling = p;
                tree_sibling[++k] = p;
            }
        } else if (s[i] == '(') {
            tree[++parent] = p;
            flag = -1;
        } else if (s[i] == ')') {
            k = 0;
            tree_sibling[k]=tree[parent];
            parent--;
        } else if (s[i] == ',') {
            flag = 1;
        }
    }
    if (strlen(s) == 1) tree[++parent] = p;
    return tree[1];
}
CSTree createTree() {
    char ch;
    cin >> ch;
    queue<CSTree> Q;
    CSTree p = new CSTNode, pr, rt;
    int flag = 0;
    p->data = ch;
    p->child = NULL;
    p->sibling = NULL;
    rt = p;
    Q.push(rt);
    while (cin >> ch) {
        if (isalpha(ch)) {
            p = new CSTNode;
            p->data = ch;
            p->child = NULL;
            p->sibling = NULL;
            if (flag == 1) {
                pr->sibling = p;
                pr = pr->sibling;
            } else if (flag == 0) {
                pr = Q.front();
                pr->child = p;
                pr = p;
                flag = 1;
            }
            Q.push(p);
        } else if (ch == '#') {
            flag = 0;
            Q.pop();
        }
    }
    return rt;
}
void preOrder(CSTree root) {
    if (root != NULL) {
        cout << root->data;
        preOrder(root->child);
        preOrder(root->sibling);
    }
}
void postOrder(CSTree root){
    if(root!=NULL){
        postOrder(root->child);
        cout<<root->data;
        postOrder(root->sibling);
    }
}