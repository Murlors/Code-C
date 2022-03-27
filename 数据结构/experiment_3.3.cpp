#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;
typedef struct{
    ElementType *data; //数据
    int size;	 		//大小
    int capacity;  		//容量
}HNode, *Heap;

Heap createHeap(int capacity);
int parent(int i);
int left(int i);
int right(int i);
int full(Heap H);
int empty(Heap H);
void swap(Heap H, int i, int j);
void increase(Heap H, int i, ElementType x);
int insert(Heap H, ElementType x);
void heapify(Heap H,int i);
void initHeap(Heap H, ElementType data[], int n);
void heapSort(Heap H);
void destroyHeap(Heap H);
ElementType front(Heap H);
int push(Heap H,ElementType x);
void pop(Heap H);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
Heap createHeap(int capacity) {
    Heap H = new HNode;
    H->data = new ElementType[capacity + 1];
    H->capacity = capacity;
    H->size = 0;
    return H;
}
int parent(int i) {
    return i / 2;
}
int left(int i) {
    return 2 * i;
}
int right(int i) {
    return 2 * i + 1;
}
int full(Heap H) {
    return H->capacity == H->size ? 1 : 0;
}
int empty(Heap H) {
    return H->size == 0 ? 1 : 0;
}
void swap(Heap H, int i, int j) {
    swap(H->data[i], H->data[j]);
}
void increase(Heap H, int i, ElementType x) {
    if (H->data[i] > x) {
        H->data[i] = x;
        while ((H->data[parent(i)] < H->data[i]) && (i != 0)) {
            swap(H, i, parent(i));
            i = parent(i);
        }
    }
}
int insert(Heap H, ElementType x) {
    if (full(H)) return 0;
    int cur = ++H->size;
    H->data[cur] = x;
    while ((H->data[parent(cur)] < H->data[cur]) && (cur != 0)) {
        swap(H, cur, parent(cur));
        cur = parent(cur);
    }
    return 1;
}
void heapify(Heap H,int i) {
    while (true) {
        int l = left(i), r = right(i), largest = i;
        if (H->size >= l && H->data[l] > H->data[largest]) largest = l;
        if (H->size >= r && H->data[r] > H->data[largest]) largest = r;
        if (largest == i) break;
        swap(H, i, largest);
        i = largest;
    }
}
void initHeap(Heap H, ElementType data[], int n) {
    for (int i = 1; i <= n; i++) {
        insert(H, data[i]);
    }
}
void  heapSort(Heap H){

}
void destroyHeap(Heap H){
    delete [] H->data;
    delete H;
}
ElementType front(Heap H){
    return H->data[1];
}
int push(Heap H,ElementType x){
    return insert(H, x);
}
void pop(Heap H) {
    H->data[1] = H->data[H->size--];
    int cur = 1;
    while (H->size >= left(cur)) {
        int l = left(cur), r = right(cur);
        if (H->size >= right(cur) && H->data[l] < H->data[r]) l = r;
        if (H->data[l] < H->data[cur]) return;
        swap(H, cur, l);
        cur = l;
    }
}