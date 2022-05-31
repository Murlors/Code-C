#include <bits/stdc++.h>
using namespace std;

typedef int ElementType;

typedef struct HashNode
{
    ElementType key;
    struct HashNode * next;
}HashNode,* List;

typedef struct
{
    int size;
    List * lists;//槽指针,所有链表均有头结点
}HashTable;

int nextPrime(int n);
HashTable * create(int size);
int hash(HashTable * h,ElementType key);
void insert(HashTable * h,ElementType key);
HashNode * findPre(HashTable * h,ElementType key);
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
HashTable * create(int size) {
    HashTable *h = new HashTable;
    h->lists = new List[size];
    h->size = size;
    for (int i = 0; i < size; ++i)
        h->lists[i] = new HashNode;
    return h;
}
int hash(HashTable * h,ElementType key) {
    return key % h->size;
}
HashNode * find(HashTable * h,ElementType key) {
    int k = hash(h, key);
    List p = h->lists[k];
    while (p->next != NULL) {
        if (p->next->key == key)return p->next;
        p = p->next;
    }
    return NULL;
}
void insert(HashTable * h,ElementType key) {
    if (find(h, key) != NULL)return;
    int k = hash(h, key);
    List p = h->lists[k]->next;
    h->lists[k]->next = new HashNode;
    h->lists[k]->next->key = key;
    h->lists[k]->next->next = p;
}
HashNode * findPre(HashTable * h,ElementType key){
    int k = hash(h, key);
    List p = h->lists[k];
    while (p->next != NULL) {
        if (p->next->key == key)return p;
        p = p->next;
    }
    return NULL;
}
void del(HashTable * h,ElementType key) {
    if (find(h, key) == NULL)return;
    List pre = findPre(h, key);
    List d = pre->next;
    pre->next = pre->next->next;
    delete d;
}

void destroy(HashTable * h) {
    for (int i = 0; i < h->size; ++i) {
        List p = h->lists[i];
        while (p->next != NULL) {
            List d = p->next;
            p->next = p->next->next;
            delete d;
            p = p->next;
        }
        delete p;
    }
    delete[]h->lists;
    delete h;
}