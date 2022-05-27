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

void Floyd(Graph g, int D[][MAXVEX], int P[][MAXVEX]);

int main()
{
    /*此处代码由测试程序自动添加，主要为了向顺序表中插入数据
	并输出数据,你无需关心此处代码的具体实现细节。
	如果有必要，请自己添加代码以测试你的函数是否正确。 
    */
    return 0;
}
/*你的提交的代码将被添加在此处，请完成题目所要求的函数的定义*/