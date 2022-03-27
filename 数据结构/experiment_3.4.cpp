#include <bits/stdc++.h>
using namespace std;

typedef int KeyType;
typedef struct
{
    KeyType value;
    int weight;
} Node;

typedef struct HTNode {
    KeyType value; //节点数值
    int weight;  //节点权
    HTNode* lchild;
    HTNode* rchild;
    int depth;

    bool operator<(const HTNode &a) const {
        return weight < a.weight || (weight == a.weight && value < a.value);
    }
} HTNode, *HuffmanTree;

typedef HuffmanTree ElementType;
typedef struct{
    ElementType * data; //数据
    int size;	 		//大小
    int capacity;  		//容量
} HNode, *Heap;

int parent(int i);
int left(int i);
int right(int i);
void swap(Heap H, int i, int j);
void heapify(Heap H,int i);
void initHeap(Heap H,Node data[],int n);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
int parent(int i) {
    return i / 2;
}
int left(int i) {
    return 2 * i;
}
int right(int i) {
    return 2 * i + 1;
}
void swap(Heap H, int i, int j) {
    swap(H->data[i], H->data[j]);
}
void heapify(Heap H,int i) {
    while (true) {
        int l = left(i), r = right(i), smallest = i;
        if (H->size >= l && H->data[l] < H->data[smallest]) smallest = l;
        if (H->size >= r && H->data[r] < H->data[smallest]) smallest = r;
        if (smallest == i) break;
        swap(H, i, smallest);
        i = smallest;
    }
}
void initHeap(Heap H,Node data[],int n) {
    for (int i = 1; i <= n; i++) {
        HuffmanTree p = new HTNode;
        p->weight = data[i].weight;
        p->value = data[i].value;
        p->depth = i >> 1;
        p->lchild = NULL;
        p->rchild = NULL;
        int l = ++H->size;
        while (p->weight < H->data[parent(l)]->weight) {
            swap(H, l, parent(l));
            l >>= 1;
        }
        heapify(H, i);
    }
}