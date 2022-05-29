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

void addVertex(Graph g, VertexType v);
void addEdge(Graph g, VertexType v1, VertexType v2, int w);

int Kruskal(Graph g);
int locateVertex(Graph g, VertexType v) {
    for (int i = 0; i < g->vertexNum; ++i)
        if (g->vexs[i].data == v)return i;
    return -1;
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
int main() {
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    int vexnum,ednum;
    cin>>vexnum>>ednum;
    Graph g=new AdjGraph ;
    g->vertexNum=vexnum;
    VertexType a,b;
    int w;
    for (int i = 0; i < vexnum; ++i)
        cin>>g->vexs[i].data;
    for (int i = 0; i < ednum; ++i) {
        cin>>a>>b>>w;
        addEdge(g,a,b,w);
    }
    cout<<Kruskal(g)<<"\n";
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
//Kruskal
struct Edge {
    int x, y, w;
}tmp;
Edge edges[MAXVEX * MAXVEX];
set<pair<int,int> > st;
int cnt,s[210];
bool cmp(const Edge a, const Edge b) {
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
/*
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType vexs[MAXVEX]; //顶点表
    EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
    int vertexNum,edgeNum;
}MGraph,*Graph;
*/
/*3163
int Kruskal(Graph g) {
    int ans = 0;
    for (int i = 0; i < g->vertexNum; ++i) {
        for (int j = 0; j < i; ++j) {
            if (g->edge[i][j] != INT_MAX) {
                tmp.x = i, tmp.y = j, tmp.w = g->edge[i][j];
                edges[cnt++] = tmp;
            }
        }
    }
    sort(edges, edges + cnt, cmp);
    cnt = 0;
    for (int i = 1; i <= g->vertexNum; ++i) s[i] = i;
    for (int i = 0; i < g->edgeNum; ++i) {
        if (merges(edges[i].x, edges[i].y)) ans += edges[i].w;
        if (cnt == g->vertexNum - 1) break;
    }
    if (cnt < g->vertexNum - 1) return -1;
    return ans;
}
*/
/*3162
int Kruskal(Graph g,Graph t) {
    int ans = 0;
    for (int i = 0; i < g->vertexNum; ++i) {
        ENode *p = g->vexs[i].firstEdge;
        while (p != NULL) {
            if (st.find(make_pair(i, p->adjVertex)) == st.end() && st.find(make_pair(p->adjVertex, i)) == st.end()) {
                tmp.x = i, tmp.y = p->adjVertex, tmp.w = p->weight;
                edges[cnt++] = tmp;
                st.insert(make_pair(i, p->adjVertex));
            }
            p = p->nextEdge;
        }
    }
    sort(edges, edges + cnt, cmp);
    cnt = 0;
    for (int i = 1; i <= g->vertexNum; ++i) s[i] = i;
    for (int i = 0; i < g->edgeNum; ++i) {
        if (merges(edges[i].x, edges[i].y)) {
            ans += edges[i].w;
            addVertex(t,edges[i].x);
            addVertex(t,edges[i].y);
            addEdge(t,edges[i].x,edges[i].y,edges[i].w);
        }
        if (cnt == g->vertexNum - 1) break;
    }
    if (cnt < g->vertexNum - 1) return -1;
    return ans;
}
*/
/*3161
int Kruskal(Graph g) {
    int ans = 0;
    for (int i = 0; i < g->vertexNum; ++i) {
        ENode *p = g->vexs[i].firstEdge;
        while (p != NULL) {
            if (st.find(make_pair(i, p->adjVertex)) == st.end() && st.find(make_pair(p->adjVertex, i)) == st.end()) {
                tmp.x = i, tmp.y = p->adjVertex, tmp.w = p->weight;
                edges[cnt++] = tmp;
                st.insert(make_pair(i, p->adjVertex));
            }
            p = p->nextEdge;
        }
    }
    sort(edges, edges + cnt, cmp);
    cnt = 0;
    for (int i = 1; i <= g->vertexNum; ++i) s[i] = i;
    for (int i = 0; i < g->edgeNum; ++i) {
        if (merges(edges[i].x, edges[i].y)) ans += edges[i].w;
        if (cnt == g->vertexNum - 1) break;
    }
    if (cnt < g->vertexNum - 1) return -1;
    return ans;
}
*/
//Prim
int findMin(int lowcost[],int n) {
    int k = -1, min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (lowcost[i] != 0 && min > lowcost[i]) {
            min = lowcost[i];
            k = i;
        }
    }
    return k;
}
/*3160
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType vexs[MAXVEX]; //顶点表
    EdgeType edge[MAXVEX][MAXVEX]; //邻接矩阵,即边表
    int vertexNum,edgeNum;
}MGraph,*Graph;
int Prim(Graph g, VertexType u) {
    int sum = 0, k = locateVertex(g, u), lowcost[MAXVEX];
    for (int i = 0; i < g->vertexNum; ++i)
        lowcost[i] = g->edge[k][i];
    lowcost[k] = 0;//!
    for (int i = 1; i < g->vertexNum; ++i) {
        k = findMin(lowcost, g->vertexNum);
        if (k == -1) return -1;
        sum += lowcost[k];
        lowcost[k] = 0;
        for (int j = 0; j < g->vertexNum; ++j)
            if (lowcost[j] != 0 && lowcost[j] > g->edge[k][j])
                lowcost[j] = g->edge[k][j];
    }
    return sum;
}
*/
/*3159
int Prim(Graph g, VertexType u,Graph t) {
    int i, j, k, sum = 0, lowcost[MAXVEX];
    ENode *p;
    addVertex(t, u);
    VertexType pre = u;
    for (i = 0; i < g->vertexNum; i++)
        lowcost[i] = INT_MAX;
    k = locateVertex(g, u);
    lowcost[k] = 0;
    p = g->vexs[k].firstEdge;
    while (p != NULL) {
        j = p->adjVertex;
        lowcost[j] = p->weight;
        p = p->nextEdge;
    }
    for (i = 1; i < g->vertexNum; i++) {
        k = findMin(lowcost, g->vertexNum);
        if (k == -1) return -1;
        sum += lowcost[k];
        addVertex(t, g->vexs[k].data);
        addEdge(t, g->vexs[k].data, pre, lowcost[k]);
        pre = g->vexs[k].data;
        lowcost[k] = 0;
        p = g->vexs[k].firstEdge;
        while (p != NULL) {
            j = p->adjVertex;
            if (lowcost[j] != 0 && lowcost[j] > p->weight)
                lowcost[j] = p->weight;
            p = p->nextEdge;
        }
    }
    return sum;
}
*/
/*3158
int Prim(Graph g, VertexType u) {
    int i, j, k, sum = 0, lowcost[MAXVEX];
    ENode *p;
    for (i = 0; i < g->vertexNum; i++) lowcost[i] = INT_MAX;
    k = locateVertex(g, u);
    lowcost[k] = 0;
    p = g->vexs[k].firstEdge;
    while (p != NULL) {
        j = p->adjVertex;
        lowcost[j] = p->weight;
        p = p->nextEdge;
    }
    for (i = 1; i < g->vertexNum; i++) {
        k = findMin(lowcost, g->vertexNum);
        if (k == -1) return -1;
        sum += lowcost[k];
        lowcost[k] = 0;
        p = g->vexs[k].firstEdge;
        while (p != NULL) {
            j = p->adjVertex;
            if (lowcost[j] != 0 && lowcost[j] > p->weight)
                lowcost[j] = p->weight;
            p = p->nextEdge;
        }
    }
    return sum;
}
*/