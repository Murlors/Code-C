#include "bits/stdc++.h"

using namespace std;

typedef int ElementType;
typedef struct Node{
    ElementType data;
    struct Node *next;
} QNode;
typedef struct{
    QNode *front; //队首
    QNode *rear;  //队尾
} LinkQueue;

LinkQueue* createQueue();
int push(LinkQueue *Q, ElementType x);
int empty(LinkQueue *Q);
int pop(LinkQueue *Q);
ElementType front(LinkQueue *Q);
void clearQueue(LinkQueue *Q);
void destroyQueue(LinkQueue *Q);

int main(){
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
LinkQueue* createQueue() {
    LinkQueue* Q = new LinkQueue;
    return Q;
}
int push(LinkQueue *Q, ElementType x) {
    if (Q->front == NULL) {
        Q->front = new(nothrow) QNode;
        if (Q->front == NULL)return 0;
        Q->rear = Q->front;
    } else {
        Q->rear->next = new(nothrow) QNode;
        if (Q->rear->next == NULL)return 0;
        Q->rear = Q->rear->next;
    }
    Q->rear->data = x;
    Q->rear->next = NULL;
    return 1;
}
int empty(LinkQueue *Q) {
    return Q->front == NULL;
}
int pop(LinkQueue *Q) {
    if (Q->front == NULL)return 0;
    if (Q->rear == Q->front) {
        Q->front = NULL;
        Q->rear = NULL;
    } else {
        QNode* p = Q->front;
        Q->front = p->next;
        delete p;
    }
    return 1;
}
ElementType front(LinkQueue *Q) {
    return Q->front->data;
}
void clearQueue(LinkQueue *Q) {
    QNode* p = Q->front;
    if (p == NULL) return;
    if (p->next == NULL) {
        Q->front = NULL;
        delete p;
    } else
        while (p->next != NULL) {
            QNode* q = p->next;
            delete p;
            p = q;
        }
    Q->front = NULL;
    Q->rear = Q->front;
}
void destroyQueue(LinkQueue *Q) {
    QNode* p = Q->front;
    if (p == NULL) return;
    Q->rear = NULL;
    if (p->next == NULL) {
        Q->front = NULL;
        delete p;
    } else
        while (p->next != NULL) {
            QNode* q = p->next;
            delete p;
            p = q;
        }
    delete Q;
}