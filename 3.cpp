#include "bits/stdc++.h"
using namespace std;
typedef string ElementType;
typedef struct Node{
    ElementType data;
    struct Node *next;
} Node, *LinkStack;
LinkStack s,l;
string op, web;
LinkStack createStack();
int push(LinkStack S, ElementType x);
int empty(LinkStack S);
int size(LinkStack S);
ElementType getTop(LinkStack S);
void destroyStack(LinkStack S);
void visit();
void back();
void forward();
int main() {
    s = new Node;
    l = new Node;
    while (cin >> op && !(op == "QUIT")) {
        if (op == "VISIT")visit();
        else if (op == "BACK")back();
        else if (op == "FORWARD")forward();
    }
    destroyStack(s);
    destroyStack(l);
    return 0;
}
int push(LinkStack S, ElementType x) {
    LinkStack p = S->next, n = new(nothrow) Node;
    if (n == NULL) return 0;
    S->next = n;
    n->next = p;
    n->data = x;
    return 1;
}
int empty(LinkStack S){
    return S->next == NULL?1:0;
}
int pop(LinkStack S) {
    LinkStack p = S;
    if (p->next == NULL) return 0;
    p = p->next;
    S->next = p->next;
    delete p;
    return 1;
}
int size(LinkStack S){
    int cnt;
    while(S->next!=NULL)cnt++;
    return cnt;
}
ElementType getTop(LinkStack S) {
    LinkStack p = S->next;
    return p->data;
}
void destroyStack(LinkStack S) {
    LinkStack p = S->next;
    S->next = NULL;
    while (p != NULL) {
        LinkStack q = p->next;
        delete p;
        p = q;
    }
}
void visit() {
    cin >> web;
    push(s, web);
    while (!empty(s)) {
        pop(l);
    }
    cout << getTop(s) << endl;
}
void back() {
    if (size(s) > 1) {
        web = getTop(s);
        pop(s);
        push(l,web);
        cout << getTop(s) << endl;
    } else cout << "Ignored" << endl;
}
void forward() {
    if (!empty(l)) {
        web = getTop(l);
        pop(l);
        push(s,web);
        cout << getTop(s) << endl;
    } else cout << "Ignored" << endl;
}