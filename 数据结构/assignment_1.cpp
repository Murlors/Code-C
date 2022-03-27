#include "bits/stdc++.h"
using namespace std;
typedef struct Node
{
    int  coef;	//系数(coefficient)
    int  exp;	//指数(exponent)
    struct Node *next;
} PolyNode, *PolyList;

PolyList createList();
void insertTail(PolyList L, int coef, int exp);
void printList(PolyList L);
void derivative(PolyList L);
void polyAdd(PolyList LA, PolyList LB,PolyList LC);
void polySub(PolyList LA, PolyList LB,PolyList LC);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
PolyList createList(){
    PolyList L = new PolyNode;
    return L;
}
void insertTail(PolyList L, int coef, int exp) {
    while (L->next != NULL)
        L = L->next;
    L->next = new Node;
    L = L->next;
    L->coef = coef;
    L->exp = exp;
}
void printList(PolyList L) {
    int flag = 1;
    if (L->next != NULL) {
        while (L->next != NULL) {
            L = L->next;
            if (flag) {
                flag = 0;
            } else {
                if (L->coef > 0) { cout << "+"; }
            }
            if (L->exp > 1) {
                if (L->coef == 1);
                else if (L->coef == -1)cout << "-";
                else cout << L->coef;
                cout << "x^" << L->exp;
            } else if (L->exp == 1) {
                if (L->coef == 1);
                else if (L->coef == -1)cout << "-";
                else cout << L->coef;
                cout << "x";
            } else { cout << L->coef; }
        }
        cout << endl;
    } else {
        cout << "0" << endl;
    }
}
void derivative(PolyList L) {
    while (L->next != NULL) {
        if (L->next->exp > 0) {
            L = L->next;
            L->coef *= L->exp;
            L->exp--;
        } else {
            PolyList t = L->next;
            L->next = NULL;
            delete t;
        }
    }
}
void polyAdd(PolyList LA, PolyList LB,PolyList LC) {
    LA = LA->next;
    LB = LB->next;
    while (LA != NULL && LB != NULL) {
        if (LA->exp > LB->exp) {
            LC->next = new Node;
            LC = LC->next;
            LC->exp = LA->exp;
            LC->coef = LA->coef;
            LA = LA->next;
        } else if (LA->exp < LB->exp) {
            LC->next = new Node;
            LC = LC->next;
            LC->exp = LB->exp;
            LC->coef = LB->coef;
            LB = LB->next;
        } else if (LA->coef + LB->coef != 0) {
            LC->next = new Node;
            LC = LC->next;
            LC->exp = LA->exp;
            LC->coef = LA->coef + LB->coef;
            LA = LA->next;
            LB = LB->next;
        } else {
            LA = LA->next;
            LB = LB->next;
        }
    }
    while (LA != NULL) {
        LC->next = new Node;
        LC = LC->next;
        LC->exp = LA->exp;
        LC->coef = LA->coef;
        LA = LA->next;
    }
    while (LB != NULL) {
        LC->next = new Node;
        LC = LC->next;
        LC->exp = LB->exp;
        LC->coef = LB->coef;
        LB = LB->next;
    }
}
void polySub(PolyList LA, PolyList LB,PolyList LC) {
    LA = LA->next;
    LB = LB->next;
    while (LA != NULL && LB != NULL) {
        if (LA->exp > LB->exp) {
            LC->next = new Node;
            LC = LC->next;
            LC->exp = LA->exp;
            LC->coef = LA->coef;
            LA = LA->next;
        } else if (LA->exp < LB->exp) {
            LC->next = new Node;
            LC = LC->next;
            LC->exp = LB->exp;
            LC->coef = -LB->coef;
            LB = LB->next;
        } else if (LA->coef - LB->coef != 0) {
            LC->next = new Node;
            LC = LC->next;
            LC->exp = LA->exp;
            LC->coef = LA->coef - LB->coef;
            LA = LA->next;
            LB = LB->next;
        } else {
            LA = LA->next;
            LB = LB->next;
        }
    }
    while (LA != NULL) {
        LC->next = new Node;
        LC = LC->next;
        LC->exp = LA->exp;
        LC->coef = LA->coef;
        LA = LA->next;
    }
    while (LB != NULL) {
        LC->next = new Node;
        LC = LC->next;
        LC->exp = LB->exp;
        LC->coef = -LB->coef;
        LB = LB->next;
    }
}