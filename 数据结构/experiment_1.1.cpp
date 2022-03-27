#include<bits/stdc++.h>
using namespace std;
typedef int ElementType;
typedef struct{
    ElementType *array; //存放数据的指针
    int length;	 		//已有数据个数
    int capacity;  		//容量
}SeqList;

void mergeList(SeqList *LA, SeqList *LB, SeqList *LC);
int getElement(SeqList *L, int i, ElementType *p);
int find(SeqList *L, ElementType x);
int insertList(SeqList *L,int i,ElementType x);
int isEmpty(SeqList *L);
void printList(SeqList *L);
int getLength(SeqList *L);
void destroyList(SeqList *L);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
void mergeList(SeqList *LA, SeqList *LB, SeqList *LC) {
    int k = 0;
    for (int i = 0; i < LA->length; i++)
        LC->array[k++] = LA->array[i];
    for (int i = 0; i < LB->length; i++)
        LC->array[k++] = LB->array[i];
    LC->length = k;

}
int getElement(SeqList *L, int i, ElementType *p) {
    i--;
    if (i < 0 || i >= L->length) return 0;
    *p = L->array[i];
    return 1;
}
int find(SeqList *L, ElementType x){
    for (int i = 0; i < L->length; ++i)
        if(L->array[i]==x)
            return i+1;
    return -1;
}
int insertList(SeqList *L,int i,ElementType x) {
    i--;
    if (i < 0 || i > L->length || L->length == L->capacity) return 0;
    else {
        for (int k = L->length - 1; k >= i; k--)
            L->array[k + 1] = L->array[k];
        L->length++;
        L->array[i] = x;
        return 1;
    }
}
int isEmpty(SeqList *L) {
    if (L->length == 0)return 1;
    return 0;
}
void printList(SeqList *L) {
    if (L->length > 0) {
        for (int i = 0; i < L->length; ++i) {
            cout << L->array[i] << " ";
        }
        cout << endl;
    }
}
int getLength(SeqList *L){
    return L->length;
}
void destroyList(SeqList *L) {
    delete[] L->array;
    delete L;
}