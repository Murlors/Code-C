#include "bits/stdc++.h"

typedef int ElementType;
typedef struct{
    ElementType *array; //存放栈数据
    int top;	 		//栈顶
    int capacity;  		//容量
} SeqStack;

SeqStack* createStack(int capacity);
int full(SeqStack *S);
int push(SeqStack *S, ElementType x);
int empty(SeqStack *S);
int pop(SeqStack *S);
void clearStack(SeqStack *S);
void destroyStack(SeqStack *S);

int main(){
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
SeqStack* createStack(int capacity) {
    SeqStack* S = new SeqStack;
    S->top = -1;
    S->capacity = capacity;
    S->array = new ElementType[capacity];
    return S;
}
int full(SeqStack *S){
    return S->capacity-1==S->top;
}
int push(SeqStack *S, ElementType x) {
    if (S->top < S->capacity - 1) {
        S->array[++S->top] = x;
        return 1;
    }
    return 0;
}
int empty(SeqStack *S) {
    return S->top == -1;
}
int pop(SeqStack *S) {
    if (S->top > -1) {
        S->top--;
        return 1;
    }
    return 0;
}
ElementType top(SeqStack *S) {
    return S->array[S->top];
}
void clearStack(SeqStack *S){
    S->top=-1;
}
void destroyStack(SeqStack *S){
    delete [] S->array;
    delete S;
}