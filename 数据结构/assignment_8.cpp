#include<bits/stdc++.h>
#define MAXVEX 1000 //最大顶点数
using namespace std;

typedef char VertexType;
typedef struct ENode{
    int adjVertex;  //该边所指的顶点编号
    int weight;     //边权
    struct ENode *nextEdge;  //下一条边
} ENode;
typedef struct VNode{
    VertexType data;   //顶点信息
    int visited; //遍历标记. 1:已遍历  0:未遍历
    ENode *firstEdge; //第一条出边
} VNode;
typedef struct{
    VNode vexs[MAXVEX];
    int vertexNum,edgeNum; //点数和边数
}AdjGraph,*Graph;

Graph createGraph();
int locateVertex(Graph g, VertexType v);
void addVertex(Graph g, VertexType v);
ENode* findEdge(Graph g, int i, int j);
void addEdge(Graph g, VertexType v1, VertexType v2, int w);
int degree(Graph g, VertexType v);
void delEdge(Graph g,VertexType x,VertexType y);
void delVertex(Graph g, VertexType v);
void DFS(Graph g, int i);
void BFS(Graph g, int i);
int connect(Graph g, VertexType x, VertexType y);
int connectedComps(Graph g);
void destroyGraph(Graph g);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
Graph createGraph() {
    Graph g = new AdjGraph;
    return g;
}
int locateVertex(Graph g, VertexType v) {
    for (int i = 0; i < g->vertexNum; ++i)
        if (g->vexs[i].data == v)return i;
    return -1;
}
void addVertex(Graph g, VertexType v) {
    if (locateVertex(g, v) != -1)return;
    g->vexs[g->vertexNum++].data = v;
}
ENode* findEdge(Graph g, int i, int j) {
    ENode *p = g->vexs[i].firstEdge;
    while (p != NULL) {
        if (p->adjVertex == j)return p;
        p = p->nextEdge;
    }
    return NULL;
}
void addEdge(Graph g, VertexType v1, VertexType v2, int w) {
    int a = locateVertex(g, v1), b = locateVertex(g, v2);
    if (a == -1 || b == -1)return;
    if (g->vexs[a].firstEdge == NULL) {
        g->edgeNum++;
        g->vexs[a].firstEdge = new ENode;
        g->vexs[a].firstEdge->adjVertex = b;
        g->vexs[a].firstEdge->weight = w;
        g->vexs[a].firstEdge->nextEdge = NULL;
    } else {
        ENode *pa = g->vexs[a].firstEdge, *pre_a;
        while (pa != NULL) {
            if (pa->adjVertex == b) {
                if (pa->weight > w) {
                    pa->weight = w;
                    ENode *pb = g->vexs[b].firstEdge;
                    while (pb != NULL) {
                        if (pb->adjVertex == a) {
                            pb->weight = w;
                            return;
                        }
                        pb = pb->nextEdge;
                    }
                }
            }
            pre_a = pa;
            pa = pa->nextEdge;
        }
        g->edgeNum++;
        pre_a->nextEdge = new ENode;
        pre_a->nextEdge->adjVertex = b;
        pre_a->nextEdge->weight = w;
        pre_a->nextEdge->nextEdge = NULL;
    }
    if (g->vexs[b].firstEdge == NULL) {
        g->vexs[b].firstEdge = new ENode;
        g->vexs[b].firstEdge->adjVertex = a;
        g->vexs[b].firstEdge->weight = w;
        g->vexs[b].firstEdge->nextEdge = NULL;
    } else {
        ENode *pb = g->vexs[b].firstEdge, *pre_b;
        while (pb != NULL) {
            pre_b = pb;
            pb = pb->nextEdge;
        }
        pre_b->nextEdge = new ENode;
        pre_b->nextEdge->adjVertex = a;
        pre_b->nextEdge->weight = w;
        pre_b->nextEdge->nextEdge = NULL;
    }
}
int degree(Graph g, VertexType v) {
    int d = 0, a = locateVertex(g, v);
    if (g->vexs[a].firstEdge != NULL) {
        ENode *pb = g->vexs[a].firstEdge;
        while (pb != NULL) {
            d++;
            pb = pb->nextEdge;
        }
    }
    return d;
}
int deledge(Graph g,VertexType i,VertexType j) {
    ENode *pre, *p, *temp;
    p = g->vexs[i].firstEdge;
    if (p != NULL) {
        if (p->adjVertex == j) {
            temp = p;
            g->vexs[i].firstEdge = p->nextEdge;
            delete temp;
            return 1;
        } else {
            pre = p;
            p = p->nextEdge;
            while (p != NULL && p->adjVertex != j) {
                pre = p;
                p = p->nextEdge;
            }
            if (p != NULL) {
                pre->nextEdge = p->nextEdge;
                delete temp;
                return 1;
            }
        }
    }
    return 0;
}
void delEdge(Graph g,VertexType x,VertexType y) {
    int i = locateVertex(g, x), j = locateVertex(g, y);
    if (i == -1 || j == -1 || i == j) return;
    int k = deledge(g, i, j);
    deledge(g, j, i);
    if (k == 1) g->edgeNum--;
}
void delVertex(Graph g, VertexType v) {
    int k, j;
    k = locateVertex(g, v);
    if (k == -1)return;
    ENode *p = g->vexs[k].firstEdge;
    while (p != NULL) {
        j = p->adjVertex;
        p = p->nextEdge;
        delEdge(g, v, g->vexs[j].data);
    }
    g->vexs[k].firstEdge = g->vexs[g->vertexNum - 1].firstEdge;
    g->vexs[k].data = g->vexs[g->vertexNum - 1].data;
    for (int i = 0; i < g->vertexNum; i++) {
        for (p = g->vexs[i].firstEdge; p != NULL; p = p->nextEdge) {
            if (p->adjVertex == g->vertexNum - 1)
                p->adjVertex = k;
        }
    }
    g->vertexNum--;
}
void DFS(Graph g, int i) {
    ENode *p = g->vexs[i].firstEdge;
    while (p != NULL) {
        if (g->vexs[p->adjVertex].visited == 0) {
            g->vexs[p->adjVertex].visited = 1;
            DFS(g, p->adjVertex);
        }
        p = p->nextEdge;
    }
}
void BFS(Graph g, int i) {
    queue<ENode *> q;
    q.push(g->vexs[i].firstEdge);
    while (!q.empty()) {
        ENode *p = q.front();
        q.pop();
        while (p != NULL) {
            if (g->vexs[p->adjVertex].visited == 0) {
                g->vexs[p->adjVertex].visited = 1;
                q.push(g->vexs[p->adjVertex].firstEdge);
            }
            p = p->nextEdge;
        }
    }
}
int connect(Graph g, VertexType x, VertexType y) {
    int a = locateVertex(g, x), b = locateVertex(g, y);
    DFS(g, a);
    return g->vexs[b].visited == 1 ? 1 : 0;
}
int connectedComps(Graph g) {
    int branch = 0;
    for (int i = 0; i < g->vertexNum; ++i) {
        if (g->vexs[i].visited == 0) {
            BFS(g, i);
            branch++;
        }
    }
    return branch;
}
void destroyGraph(Graph g) {
    for (int i = 0; i < g->vertexNum; ++i) {
        ENode *p = g->vexs[i].firstEdge, *pre = p;
        if (p != NULL) {
            while (p->nextEdge != NULL) {
                pre = p;
                p = p->nextEdge;
                delete pre;
            }
            g->vexs[i].firstEdge = NULL;
            delete p;
        }
    }
    delete g;
}