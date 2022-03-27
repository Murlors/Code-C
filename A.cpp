#include<bits/stdc++.h>
using namespace std;
typedef char ElementType;
typedef class Tree {
public:
    ElementType data;
    Tree* lchild;
    Tree* rchild;
    Tree* create(Tree* root);
    void print();
    void InOrder(Tree* root, string &In);
}BTNode,*BTree;
int main() {
    BTree root= root->create(root);
    root->print();
    return 0;
}
Tree* Tree::create(Tree* root) {
    char ch = getchar();
    if (ch == '.') return NULL;
    else {
        root = new BTNode;
        root->data = ch;
        root->lchild = create(root->lchild);
        root->rchild = create(root->rchild);
        return root;
    }
}
void Tree::print() {
    queue<BTree> q;
    q.push(this);
    string InOrd;
    this->InOrder(this, InOrd);
    while (!q.empty()) {
        vector<BTree> cache;
        while (!q.empty()) {
            cache.push_back(q.front());
            q.pop();
        }
        int i = 0;
        for (int k = 0; k < cache.size(); k++)
            if (cache[k]) {
                for (; i < InOrd.find(cache[k]->data); ++i) cout << "-";
                cout << cache[k]->data;
                i++;
                if (cache[k]->lchild) q.push(cache[k]->lchild);
                if (cache[k]->rchild) q.push(cache[k]->rchild);
            }
        cout << endl;
    }
}
void Tree::InOrder(BTree root,string &In) {
    if (root) {
        InOrder(root->lchild, In);
        In += root->data;
        InOrder(root->rchild, In);
    }
}