#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 100 /*最大顶点数*/
typedef char VertexType;

struct AOENetworkStruct;
typedef struct AOENetworkStruct *AOENetwork;

typedef struct ENode
{
    int adjVertex;  //边的终点编号
    int weight;     //边权
    int earliest;   //活动最早开始时间
    int latest;     //活动最晚开始时间
    struct ENode *nextEdge;  //下一条边
} ENode;

typedef struct VNode
{
    VertexType data;    //顶点信息/
    int inDegree;       //入度/
    int earliest;       //事件最早发生时间/
    int latest;         //事件最晚发生时间
    ENode *firstEdge; //第一条出边
} VNode;

struct AOENetworkStruct
{
    VNode vexs[MAXVEX];    //点表
    int vertexNum, edgeNum; //顶点数和弧数
};

AOENetwork createGraph();
int locateVertex(AOENetwork g, VertexType v);
void addVertex(AOENetwork g, VertexType v);
ENode* findEdge(AOENetwork g, int i, int j);
void addEdge(AOENetwork g, VertexType v1, VertexType v2, int w);
int TopSort(AOENetwork g);
void event(AOENetwork g);
int active(AOENetwork g);
int pathNum(AOENetwork g);

int main() {
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
    int vnum, w;
    VertexType ch, x, y;
    cin >> vnum;
    AOENetwork g = createGraph();
    for (int i = 0; i < vnum; ++i) {
        cin >> ch;
        addVertex(g, ch);
    }
    while (cin >> x >> y, !(x == '0' && y == '0')) {
        cin >> w;
        addEdge(g, x, y, w);
    }
    event(g);
    active(g);
    cout << pathNum(g) << "\n";
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
AOENetwork createGraph() {
    AOENetwork g = new AOENetworkStruct;
    g->edgeNum = 0;
    g->vertexNum = 0;
    return g;
}
int locateVertex(AOENetwork g, VertexType v) {
    for (int i = 0; i < g->vertexNum; ++i)
        if (g->vexs[i].data == v)
            return i;
    return -1;
}
void addVertex(AOENetwork g, VertexType v) {
    if (locateVertex(g, v) != -1) return;
    g->vexs[g->vertexNum++].data = v;
}
ENode* findEdge(AOENetwork g, int i, int j) {
    ENode *p = g->vexs[i].firstEdge;
    if (p != NULL) {
        while (p != NULL) {
            if (p->adjVertex == j)return p;
            p = p->nextEdge;
        }
    }
    return NULL;
}
void addEdge(AOENetwork g, VertexType v1, VertexType v2, int w) {
    int i = locateVertex(g, v1), j = locateVertex(g, v2);
    if (i == -1 || j == -1)return;
    ENode *tmp = findEdge(g, i, j);
    if (tmp != NULL) {
        if (tmp->weight > w)
            tmp->weight = w;
        return;
    }
    ENode *ne = new ENode;
    ne->adjVertex = j;
    ne->weight = w;
    ne->nextEdge = g->vexs[i].firstEdge;
    g->vexs[i].firstEdge = ne;
    g->vexs[j].inDegree++;
    g->edgeNum++;
    //尾插错误的
    //ENode *ne = new ENode, *p = g->vexs[i].firstEdge;
    //ne->adjVertex = j;
    //ne->weight = w;
    //ne->nextEdge = NULL;
    //g->vexs[j].inDegree++;
    //g->edgeNum++;
    //if (p == NULL) {
    //    g->vexs[i].firstEdge = ne;
    //} else {
    //    while (p->nextEdge != NULL)p = p->nextEdge;
    //    p->nextEdge = ne;
    //}
}
int TopSort(AOENetwork g) {
    int cnt = 0, i, j;
    stack<int> in;
    for (int k = 0; k < g->vertexNum; ++k){
        g->vexs[k].earliest = 0;
        if (g->vexs[k].inDegree == 0)
            in.push(k);
    }
    while (!in.empty()) {
        i = in.top();
        in.pop();
        cnt++;
        ENode *p = g->vexs[i].firstEdge;
        while (p != NULL) {
            j = p->adjVertex;
            g->vexs[j].inDegree--;
            if (g->vexs[j].inDegree == 0)
                in.push(j);
            if (g->vexs[j].earliest < g->vexs[i].earliest + p->weight)
                g->vexs[j].earliest = g->vexs[i].earliest + p->weight;
            p = p->nextEdge;
        }
    }
    return (cnt < g->vertexNum) ? 0 : 1;
}
void event(AOENetwork g) {
    int i, j;
    stack<int> in, out;
    for (int k = 0; k < g->vertexNum; ++k) {
        g->vexs[k].earliest = 0;
        if (g->vexs[k].inDegree == 0)
            in.push(k);
    }
    while (!in.empty()) {
        i = in.top();
        in.pop();
        out.push(i);
        ENode *p = g->vexs[i].firstEdge;
        while (p != NULL) {
            j = p->adjVertex;
            g->vexs[j].inDegree--;
            if (g->vexs[j].inDegree == 0)
                in.push(j);
            if (g->vexs[j].earliest < g->vexs[i].earliest + p->weight)
                g->vexs[j].earliest = g->vexs[i].earliest + p->weight;
            p = p->nextEdge;
        }
    }
    for (int k = 0; k < g->vertexNum; ++k)
        g->vexs[k].latest = g->vexs[g->vertexNum - 1].earliest;
    while (!out.empty()) {
        i = out.top();
        out.pop();
        ENode *p = g->vexs[i].firstEdge;
        while (p != NULL) {
            j = p->adjVertex;
            if (g->vexs[i].latest > g->vexs[j].latest - p->weight)
                g->vexs[i].latest = g->vexs[j].latest - p->weight;
            p = p->nextEdge;
        }
    }
}
int active(AOENetwork g) {
    int cnt = 0, i, j;
    for (i = 0; i < g->vertexNum; i++) {
        ENode *p = g->vexs[i].firstEdge;
        while (p != NULL) {
            j = p->adjVertex;
            p->earliest = g->vexs[i].earliest;
            p->latest = g->vexs[j].latest - p->weight;
            if (p->earliest == p->latest) cnt++;
            p = p->nextEdge;
        }
    }
    return cnt;
}
int DFS(AOENetwork g,int x) {
    if (x == g->vertexNum - 1)return 1;
    int n = 0;
    ENode *p = g->vexs[x].firstEdge;
    while (p != NULL) {
        if (p->earliest == p->latest)
            n += DFS(g, p->adjVertex);
        p = p->nextEdge;
    }
    return n;
}
int pathNum(AOENetwork g){
    return DFS(g,0);
}