#include<bits/stdc++.h>

const int maxn = 1e6 + 1;

inline int read()
{
    register int x = 0, ch = getchar(), f = 1;
    while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

int n, m;

struct node{
    int u;
    int v;
    int w;
}e[maxn];

int fa[maxn], cnt, sum, num;

void add(int x, int y, int w)
{
    e[++ cnt].u = x;
    e[cnt].v = y;
    e[cnt].w = w;
}

bool cmp(node x, node y)
{
    return x.w < y.w;
}

int find(int x)
{
    return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);//路径压缩
}

/*
int find(int x)
{
	if(fa[x] == x) return x;
  	else
	{
   		 fa[x] = find(fa[x]);//路径压缩
   		 return fa[x];
    	}
}
*/

void kruskal()
{
    for(int i = 1; i <= cnt; i ++)
    {
        int x = find(e[i].u);
        int y = find(e[i].v);
        if(x == y) continue;
        fa[x] = y;
        sum += e[i].w;
        if(++ num == n - 1) break;//如果构成了一颗树
    }
}

int main()
{
    n = read();
    m = read();
    for(int i = 1; i <= n; i ++) fa[i] = i;
    while(m --)
    {
        int x, y, w;
        x = read();
        y = read();
        w = read();
        add(x, y, w);
    }
    std:: sort(e + 1, e + 1 + cnt, cmp);
    kruskal();
    printf("%d",sum);
    return 0;
}
