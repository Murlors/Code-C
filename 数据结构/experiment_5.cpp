#include <bits/stdc++.h>
using namespace std;

#define USED 1
#define EMPTY 0

typedef int ElementType;

typedef struct{
    ElementType key; //关键数字
    int flag;        //状态标志：USED(槽已用)或EMPTY(空闲)
}Cell;

typedef struct{
    Cell *cells;  //散列表槽指针
    int capacity; //散列表容量
    int size;     //散列表大小
}HashTable;

int nextPrime(int n);
HashTable * create(int capacity);
int hash(HashTable * h,ElementType key);
int find(HashTable * h,ElementType key);
void insert(HashTable * h,ElementType key);
void rehash(HashTable * h);
void destroy(HashTable * h);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
bool IsPrime(int n) {
    if (n < 2)return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}
int nextPrime(int n) {
    if (!(n & 1))n++;
    for (;; n += 2) {
        if (IsPrime(n))return n;
    }
}
HashTable * create(int capacity) {
    HashTable *h = new HashTable;
    h->capacity = nextPrime(capacity);
    h->size = 0;
    h->cells = new Cell[h->capacity];
    return h;
}
int hash(HashTable * h,ElementType key) {
    return key % h->capacity;
}
int find(HashTable * h,ElementType key) {
    int k = hash(h, key);
    for (int i = 0; h->cells[k].flag == USED && h->cells[k].key != key; i++) {
        k += i * i;
        k = hash(h, k);
    }
    return k;
}
void insert(HashTable * h,ElementType key) {
    int p = find(h, key);
    if (h->cells[p].key == key)return;
    h->cells[p].key = key;
    h->cells[p].flag = USED;
    h->size++;
}
void rehash(HashTable * h) {
    Cell *preCells = h->cells;
    int preCap = h->capacity;
    h->capacity = nextPrime(preCap * 2);
    h->size = 0;
    h->cells = new Cell[h->capacity];
    for (int i = 0; i < preCap; ++i)
        if (preCells[i].flag == USED)
            insert(h, preCells[i].key);
    delete[]preCells;
}
void insert(HashTable * h,ElementType key) {
    int p = find(h, key);
    if (h->cells[p].key == key)return;
    if (h->size * 2 > h->capacity)rehash(h);
    p = find(h, key);
    h->cells[p].key = key;
    h->cells[p].flag = USED;
    h->size++;
}
void destroy(HashTable * h) {
    delete[]h->cells;
    delete h;
}