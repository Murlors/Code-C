#include<bits/stdc++.h>

#define MAXVEX 100
using namespace std;
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType vexs[MAXVEX]; //顶点表
    EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
    int visited[MAXVEX];//遍历标记. 1:已遍历  0:未遍历
    int vertexNum, edgeNum;
} MGraph, *Graph;

Graph createGraph();
int locateVertex(Graph g, VertexType v);
void addVertex(Graph g, VertexType v);
void addEdge(Graph g, VertexType x, VertexType y);
void delEdge(Graph g, VertexType x, VertexType y);
void delVertex(Graph g, VertexType v);
int degree(Graph g, VertexType v);
void DFS(Graph g, int i);
void BFS(Graph g, int i);
int connect(Graph g, VertexType v, VertexType u);
int connectedComps(Graph g);
void destroyGraph(Graph g);
int distance(Graph g,VertexType v, VertexType u);

int main() {
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}

/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
Graph createGraph() {
    Graph g = new MGraph;
    g->edgeNum = 0;
    g->vertexNum = 0;
    return g;
}
int locateVertex(Graph g, VertexType v) {
    for (int i = 0; i < g->vertexNum; ++i)
        if (g->vexs[i] == v)return i;
    return -1;
}
void addVertex(Graph g, VertexType v) {
    if (locateVertex(g, v) != -1)return;
    g->vexs[g->vertexNum++] = v;
}
void addEdge(Graph g, VertexType x, VertexType y) {
    int a = locateVertex(g, x), b = locateVertex(g, y);
    if (a == -1 || b == -1)return;
    if (g->edge[a][b] == 1)return;
    g->edge[a][b] = 1;
    g->edge[b][a] = 1;
    g->edgeNum++;
}
void delEdge(Graph g, VertexType x, VertexType y) {
    int a = locateVertex(g, x), b = locateVertex(g, y);
    if (a == -1 || b == -1)return;
    if (g->edge[a][b] == 0)return;
    g->edge[a][b] = 0;
    g->edge[b][a] = 0;
    g->edgeNum--;
}
void delVertex(Graph g, VertexType v) {
    int k = locateVertex(g, v), n = g->vertexNum - 1;
    if (k == -1)return;
    g->vexs[k] = g->vexs[n];
    for (int i = 0; i < g->vertexNum; i++)
        if (g->edge[i][k] == 1)g->edgeNum--;
    for (int i = 0; i < g->vertexNum; i++) {
        g->edge[i][k] = g->edge[i][n];
        g->edge[k][i] = g->edge[n][i];
    }
    g->vertexNum--;
}
int degree(Graph g, VertexType v) {
    int k = locateVertex(g, v), d;
    for (int i = 0; i < g->vertexNum; ++i)
        if (g->edge[k][i] == 1) d++;
    return d;
}
void DFS(Graph g, int i) {
    for (int j = 0; j < g->vertexNum; ++j) {
        if (g->edge[i][j] == 1 && g->visited[j] == 0) {
            g->visited[j] = 1;
            DFS(g, j);
        }
    }
}
void BFS(Graph g, int i) {
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for (int j = 0; j < g->vertexNum; ++j) {
            if (g->edge[n][j] == 1 && g->visited[j] == 0) {
                g->visited[j] = 1;
                q.push(j);
            }
        }
    }
}
int connect(Graph g, VertexType v, VertexType u) {
    int a = locateVertex(g, v), b = locateVertex(g, u);
    DFS(g, a);
    return g->visited[b] == 1 ? 1 : 0;
}
int connectedComps(Graph g) {
    int branch = 0;
    for (int i = 0; i < g->vertexNum; ++i) {
        if (g->visited[i] == 0) {
            BFS(g, i);
            branch++;
        }
    }
    return branch;
}
int distance(Graph g,VertexType v, VertexType u) {
    int a = locateVertex(g, v), b = locateVertex(g, u);
    for (int i = 0; i < g->vertexNum; ++i) g->visited[i] = -1;
    queue<int> q;
    q.push(a);
    g->visited[a] = 0;
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for (int j = 0; j < g->vertexNum; ++j) {
            if (g->edge[n][j] == 1 && g->visited[j] == -1) {
                g->visited[j] = g->visited[n] + 1;
                if (j == b) {
                    while (!q.empty()) q.pop();
                    break;
                }
                q.push(j);
            }
        }
    }
    if (g->visited[b] == -1)return 0;
    return g->visited[b];
}
void destroyGraph(Graph g) {
    delete g;
}