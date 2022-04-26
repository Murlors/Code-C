#include <bits/stdc++.h>
using namespace std;

typedef int KeyType;
typedef struct {
    KeyType value;
    int weight;
} Node;
typedef struct HTNode {
    KeyType value; //节点数值
    int weight;  //节点权
    HTNode *lchild;
    HTNode *rchild;
    int depth;
    bool operator<(const HTNode &a) const {
        return weight < a.weight || (weight == a.weight && value < a.value);
    }
} HTNode, *HuffmanTree;
typedef HuffmanTree ElementType;
typedef struct {
    ElementType *data; //数据
    int size;            //大小
    int capacity;        //容量
} HNode, *Heap;

Heap createHeap(int capacity);
int parent(int i);
int left(int i);
int right(int i);
void swap(Heap H, int i, int j);
void heapify(Heap H, int i);
void initHeap(Heap H, Node data[], int n);
ElementType front(Heap H);
void push(Heap H, ElementType x);
void pop(Heap H);
void destroyHeap(Heap H);
HuffmanTree createHuffmanTree(Node data[], int n);
void huffmanCode(HuffmanTree HT, int code[], int depth);
void initDepth(HuffmanTree HT, int depth);
int getWPL(HuffmanTree HT);

int main() {
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
void swap(Heap H, int i, int j) {
    swap(H->data[i], H->data[j]);
}
void heapify(Heap H, int i) {
    while (true) {
        int l = left(i), r = right(i), smallest = i;
        if (H->size >= l && *(H->data[l]) < *(H->data[smallest])) smallest = l;
        if (H->size >= r && *(H->data[r]) < *(H->data[smallest])) smallest = r;
        if (smallest == i) break;
        swap(H, i, smallest);
        i = smallest;
    }
}
void initHeap(Heap H, Node data[], int n) {
    for (int i = 1; i <= n; i++) {
        HuffmanTree p = new HTNode;
        p->weight = data[i].weight;
        p->value = data[i].value;
        p->depth = 0;
        p->lchild = NULL;
        p->rchild = NULL;
        H->data[i] = p;
    }
    H->size = n;
    for (int i = n; i >= 1; i--) heapify(H, i);
}
ElementType front(Heap H) {
    return H->data[1];
}
void push(Heap H, ElementType x) {
    int i = ++H->size;
    H->data[i] = x;
    while (i != 1 && *(H->data[i]) < *(H->data[parent(i)])) {
        swap(H, i, parent(i));
        i = parent(i);
    }
}
void pop(Heap H) {
    H->data[1] = H->data[H->size--];
    heapify(H, 1);
}
void destroyHeap(Heap H) {
    delete[] H->data;
    delete H;
}
HuffmanTree createHuffmanTree(Node data[], int n) {
    Heap H = createHeap(n);
    initHeap(H, data, n);
    while (H->size > 1) {
        HuffmanTree l, r, p = new HTNode;
        l = front(H);
        pop(H);
        r = front(H);
        pop(H);
        p->lchild = l;
        p->rchild = r;
        p->weight = l->weight + r->weight;
        p->value = min(l->value, r->value);
        push(H, p);
    }
    HuffmanTree HT = front(H);
    pop(H);
    destroyHeap(H);
    return HT;
}
void huffmanCode(HuffmanTree HT, int code[], int depth) {
    if (HT != NULL) {
        if (HT->lchild == NULL && HT->rchild == NULL) {
            cout << HT->value << ":";
            for (int i = 0; i < depth; ++i)
                cout << code[i];
            cout << "\n";
            return;
        }
        code[depth] = 0;
        huffmanCode(HT->lchild, code, depth + 1);
        code[depth] = 1;
        huffmanCode(HT->rchild, code, depth + 1);
    }
}
void initDepth(HuffmanTree HT, int depth) {
    if (HT != NULL) {
        HT->depth = depth;
        initDepth(HT->lchild, depth + 1);
        initDepth(HT->rchild, depth + 1);
    }
}
int getWPL(HuffmanTree HT) {
    if (HT != NULL) {
        if (HT->lchild == NULL && HT->rchild == NULL)
            return HT->depth * HT->weight;
        return getWPL(HT->lchild) + getWPL(HT->rchild);
    }
    return 0;
}