#include<bits/stdc++.h>
using namespace std;
#define MAXVEX 200 //最大顶点数
typedef char VertexType;
typedef struct ENode {
    int adjVertex;  //该边所指的顶点编号
    int weight;     //边权
    struct ENode *nextEdge;  //下一条边
} ENode;
typedef struct VNode {
    VertexType data;   //顶点信息
    ENode *firstEdge; //第一条出边
} VNode;
typedef struct {
    VNode vexs[MAXVEX];
    int vertexNum, edgeNum; //点数和边数
} AdjGraph, *Graph;

int Kruskal(Graph g);

int main() {
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
struct t {
    int x, y, w;
}tmp;
vector<t> arr;
set<pair<int,int> > st;
int cnt,s[210];
bool cmp(const t a, const t b) {
    return a.w < b.w;
}
int finds(int x) {
    while (s[x] != x) x = s[x];
    return x;
}
int merges(int a, int b) {
    int fa = finds(a), fb = finds(b);
    if (fa != fb) {
        s[fa] = fb;
        cnt++;
        return 1;
    }
    return 0;
}
int Kruskal(Graph g) {
    int ans = 0;
    for (int i = 0; i < g->vertexNum; ++i) {
        queue<ENode *> q;
        q.push(g->vexs[i].firstEdge);
        while (!q.empty()) {
            ENode *p = q.front();
            q.pop();
            while (p != NULL) {
                if (st.find(make_pair(i, p->adjVertex)) == st.end() && st.find(make_pair(p->adjVertex, i)) == st.end()) {
                    tmp.x = i, tmp.y = p->adjVertex, tmp.w = p->weight;
                    arr.push_back(tmp);
                    st.insert(make_pair(i, p->adjVertex));
                    q.push(g->vexs[p->adjVertex].firstEdge);
                }
                p = p->nextEdge;
            }
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < g->vertexNum; ++i) s[i] = i;
    for (int i = 0; i < g->edgeNum; ++i) {
        if (merges(arr[i].x, arr[i].y)) ans += arr[i].w;
        if (cnt == g->vertexNum - 1) break;
    }
    if (cnt < g->vertexNum - 1) return -1;
    return ans;
}