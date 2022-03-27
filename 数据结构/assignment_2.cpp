#include "bits/stdc++.h"

using namespace std;

typedef int ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node, *LinkStack;

LinkStack createStack();
int push(LinkStack S, ElementType x);
int empty(LinkStack S);
ElementType getTop(LinkStack S);
void clearStack(LinkStack S);
void destroyStack(LinkStack S);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
LinkStack createStack() {
    LinkStack S = new Node;
    return S;
}
int push(LinkStack S, ElementType x) {
    LinkStack p = S->next, n = new(nothrow) Node;
    if (n == NULL) return 0;
    S->next = n;
    n->next = p;
    n->data = x;
    return 1;
}
int empty(LinkStack S){
    return S->next == NULL;
}
int pop(LinkStack S) {
    LinkStack p = S;
    if (p->next == NULL) return 0;
    p = p->next;
    S->next = p->next;
    delete p;
    return 1;
}
ElementType getTop(LinkStack S) {
    LinkStack p = S->next;
    return p->data;
}
void clearStack(LinkStack S){
    S->next=NULL;
}
void destroyStack(LinkStack S) {
    LinkStack p = S->next;
    S->next = NULL;
    while (p != NULL) {
        LinkStack q = p->next;
        delete p;
        p = q;
    }
}