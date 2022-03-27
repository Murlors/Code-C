#include "bits/stdc++.h"

using namespace std;

typedef int ElementType;
typedef struct Node{
    ElementType data;
    struct Node  *next;
}Node, *LinkList;

LinkList createList();
void printList(LinkList L);
int getLength(LinkList L);
void insertHead(LinkList L, ElementType x);
void insertTail(LinkList  L, ElementType x);
int insertList(LinkList L, int i, ElementType x);
Node* find(LinkList L, ElementType x);
Node* locate(LinkList L, int i);
int delNode(LinkList L, ElementType x);
int delNode(LinkList L, int i, ElementType *px);
void clearList(LinkList L);
void destroyList(LinkList L);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
LinkList createList(){
    LinkList L=new Node;
    return L;
}
void printList(LinkList L) {
    L = L->next;
    if (L != NULL) {
        while (L != NULL) {
            cout << L->data << " ";
            L = L->next;
        }
        cout << endl;
    }
}
int getLength(LinkList L) {
    int count = 0;
    L = L->next;
    while (L != NULL) {
        count++;
        L = L->next;
    }
    return count;
}
void insertHead(LinkList L, ElementType x) {
    LinkList p = new Node;
    p->next=L->next;
    p->data=x;
    L->next=p;
}
void insertTail(LinkList  L, ElementType x) {
    while (L->next != NULL)
        L = L->next;
    L->next=new Node;
    L=L->next;
    L->data=x;
}
int insertList(LinkList L, int i, ElementType x) {
    LinkList p;
    int k = 0;
    while (L != NULL && k < i - 1) {
        k++;
        L = L->next;
    }
    if (L == NULL || i < 1) return 0;
    p = new Node;
    p->data = x;
    p->next = L->next;
    L->next = p;
    return 1;
}
Node* find(LinkList L, ElementType x) {
    LinkList p = L;
    while (p->next != NULL) {
        p = p->next;
        if (p->data == x) {
            return p;
        }
    }
    return NULL;
}
Node* locate(LinkList L, int i) {
    int count;
    LinkList p = L;
    while (p->next != NULL) {
        p = p->next;
        if (++count == i) {
            return p;
        }
    }
    return NULL;
}
int delNode(LinkList L, ElementType x) {
    LinkList p = L;
    while (p->next != NULL) {
        if (p->next->data == x) {
            p->next=p->next->next;
            return 1;
        }
        p = p->next;
    }
    return 0;
}
int delNode(LinkList L, int i, ElementType *px) {
    int count;
    LinkList p = L;
    while (p->next != NULL) {
        if (++count == i) {
            *px = p->next->data;
            p->next = p->next->next;
            return 1;
        }
        p = p->next;
    }
    return 0;
}
void clearList(LinkList L) {
    LinkList p = L, n = L->next;
    while (n != NULL) {
        p = n->next;
        delete n;
        n = p;
    }
    L->next = NULL;
}
void destroyList(LinkList L) {
    LinkList p = L, n = L->next;
    while (n != NULL) {
        p = n->next;
        delete n;
        n = p;
    }
    delete L;
}