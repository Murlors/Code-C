#include "bits/stdc++.h"

typedef int ElementType;
typedef struct{
    ElementType *array;
    int front;      //队首位置
    int rear;       //尾指下一个位置
    int length;     //长度
    int capacity;   //总容量
}SeqQueue;

SeqQueue* createQueue(int capacity);
int full(SeqQueue *Q);
ElementType front(SeqQueue *Q);
void clearQueue(SeqQueue *Q);
void destroyQueue(SeqQueue *Q);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
SeqQueue* createQueue(int capacity) {
    SeqQueue* Q = new SeqQueue;
    Q->array = new ElementType[capacity];
    Q->front = 0;
    Q->rear = 0;
    Q->length = 0;
    Q->capacity = capacity;
    return Q;
}
int full(SeqQueue *Q) {
    return Q->length == Q->capacity;
}
int push(SeqQueue *Q, ElementType x) {
    if (Q->length == Q->capacity)return 0;
    Q->array[Q->rear++] = x;
    Q->length++;
    return 1;
}
int empty(SeqQueue *Q) {
    return Q->length == 0;
}
int pop(SeqQueue  *Q, ElementType  *x) {
    if (Q->front == Q->rear)return 0;
    *x = Q->array[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    Q->length--;
    return 1;
}
ElementType front(SeqQueue *Q){
    return Q->array[Q->front];
}
void clearQueue(SeqQueue *Q){
    Q->front=0;
    Q->rear=0;
    Q->length=0;
}
void destroyQueue(SeqQueue *Q) {
    delete[] Q->array;
    delete Q;
}