#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
#define down(i, x, y) for (int i = (x); i >= (y); i--)
#define MAXN 100010

int a[MAXN], b[MAXN], root[MAXN], lson[MAXN << 5], rson[MAXN << 5], sum[MAXN << 5];
int tot,t,n,m,st, ed, k;

inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

int build(int l, int r)
{
    int rt = ++tot;
    sum[rt] = 0;
    if (l < r)
    {
        int mid = (l + r) >> 1;
        lson[rt] = build(l, mid);
        rson[rt] = build(mid + 1, r);
    }
    return rt;
}

int update(int p, int l, int r, int x)
{
    int rt = ++tot;
    lson[rt] = lson[p], rson[rt] = rson[p], sum[rt] = sum[p] + 1;
    if (l < r)
    {
        int mid = (l + r) >> 1;
        if (x <= mid)
            lson[rt] = update(lson[rt], l, mid, x);
        else
            rson[rt] = update(rson[rt], mid + 1, r, x);
    }
    return rt;
}

int query(int u, int v, int l, int r, int k)
{
    if (l == r)
        return l;
    int x = sum[lson[v]] - sum[lson[u]];
    int mid = (l + r) >> 1;
    if (x >= k)
        return query(lson[u], lson[v], l, mid, k);
    else
        return query(rson[u], rson[v], mid + 1, r, k - x);
}

int main() {
    n = read(), m = read(), tot = 0;
    //离散化
    rep(i, 1, n)a[i] = b[i] = read();
    std::sort(b + 1, b + n + 1);
    int nn = std::unique(b + 1, b + n + 1) - b - 1;
    root[0] = build(1, m);
    rep(i, 1, n) {
        a[i] = std::lower_bound(b + 1, b + nn + 1, a[i]) - b;
        root[i] = update(root[i - 1], 1, nn, a[i]);
    }
    rep(i, 1, m) {
        st = read(), ed = read(), k = read();
        printf("%d\n", b[query(root[st - 1], root[ed], 1, nn, k)]);
    }
    return 0;
}