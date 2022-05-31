#include<bits/stdc++.h>
using namespace std;

#define MAXVEX 200 //最大顶点数
typedef char VertexType;

typedef struct ENode
{
    int adjVertex;  //该边所指的顶点编号
    int weight;     //边权
    struct ENode *nextEdge;  //下一条边
} ENode;

typedef struct VNode
{
    VertexType data;   //顶点信息
    int visited; //遍历标记. 1:已遍历  0:未遍历
    ENode *firstEdge; //第一条出边
} VNode;

typedef struct
{
    VNode vexs[MAXVEX];
    int vertexNum,edgeNum; //点数和边数
}AdjGraph,*Graph;

void Dijkstra(Graph g, int s, int D[], int P[]);
void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX]);

int main(){
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/
int findMin(Graph g,int D[],int final[]) {
    int i, k = -1, min = INT_MAX;
    for (i = 0; i < g->vertexNum; i++) {
        if (final[i] != 1 && min > D[i]) {
            min = D[i];
            k = i;
        }
    }
    return k;
}
/*3164
void Dijkstra(Graph g, int s, int D[], int P[]) {
    int i, k, final[MAXVEX];
    for (i = 0; i < g->vertexNum; i++)
        D[i] = INT_MAX, final[i] = 0;
    ENode *p = g->vexs[s].firstEdge;
    while (p != NULL) {
        i = p->adjVertex;
        D[i] = p->weight;
        P[i] = s;
        p = p->nextEdge;
    }
    P[s] = s;
    final[s] = 1;
    D[s] = 0;
    while (true) {
        k = findMin(g, D, final);
        if (k == -1) return;
        final[k] = 1;
        p = g->vexs[k].firstEdge;
        while (p != NULL) {
            i = p->adjVertex;
            if (final[i] != 1 && D[i] > D[k] + p->weight) {
                D[i] = D[k] + p->weight;
                P[i] = k;
            }
            p = p->nextEdge;
        }
    }
}
*/
/*3166
void Dijkstra(Graph g, int s, int D[], int P[]) {
    int i, k, final[MAXVEX];
    for (i = 0; i < g->vertexNum; i++) {
        D[i] = g->edge[s][i];
        if (D[i] < INT_MAX)P[i] = s;
        final[i] = 0;
    }
    final[s] = 1;
    P[s] = s;
    D[s] = 0;
    while (true) {
        k = findMin(g, D, final);
        if (k == -1)return;
        final[k] = 1;
        for (i = 0; i < g->vertexNum; i++)
            if (!(g->edge[k][i] == INT_MAX || final[i]))
                if (D[i] > D[k] + g->edge[k][i])
                    D[i] = D[k] + g->edge[k][i], P[i] = k;
    }
}
*/
/*3165
void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX]) {
    int i, j, k, n;
    n = g->vertexNum;
    ENode *p;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            D[i][j] = i == j ? 0 : INT_MAX, P[i][j] = i;
    for (i = 0; i < n; i++) {
        p = g->vexs[i].firstEdge;
        while (p != NULL) {
            j = p->adjVertex;
            D[i][j] = p->weight;
            p = p->nextEdge;
        }
    }
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            if (D[i][k] != INT_MAX)
                for (j = 0; j < n; j++)
                    if (!(i == j || D[k][j] == INT_MAX))
                        if (D[i][j] > D[i][k] + D[k][j])
                            D[i][j] = D[i][k] + D[k][j], P[i][j] = P[k][j];
}
*/
/*3167
void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX]) {
    int i, j, k, n;
    n = g->vertexNum;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            D[i][j] = i == j ? 0 : g->edge[i][j], P[i][j] = i;
    for (k = 0; k < n; k++)
        for (i = 0; i < n; i++)
            if (D[i][k] != INT_MAX)
                for (j = 0; j < n; j++)
                    if (!(i == j || D[k][j] == INT_MAX))
                        if (D[i][j] > D[i][k] + D[k][j])
                            D[i][j] = D[i][k] + D[k][j], P[i][j] = P[k][j];
}
*/