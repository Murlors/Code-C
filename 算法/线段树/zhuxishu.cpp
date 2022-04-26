#include <bits/stdc++.h>
#define MAXN 100010
using namespace std;
typedef pair<int,int> pairint;
struct cmp {
    bool operator()(const pairint &n1, const pairint &n2) const {
        return n1.second < n2.second;
    }
};
pairint a[MAXN], b[MAXN];
int root[MAXN], lson[MAXN << 5], rson[MAXN << 5], sum[MAXN << 5];
int t, n, m, tot, st, ed, k;
inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int build(int l, int r) {
    int rt = ++tot;
    sum[rt] = 0;
    if (l < r) {
        int mid = (l + r) >> 1;
        lson[rt] = build(l, mid);
        rson[rt] = build(mid + 1, r);
    }
    return rt;
}
int update(int p, int l, int r, int x) {
    int rt = ++tot;
    lson[rt] = lson[p], rson[rt] = rson[p], sum[rt] = sum[p] + 1;
    if (l < r) {
        int mid = (l + r) >> 1;
        if (x <= mid)
            lson[rt] = update(lson[p], l, mid, x);
        else
            rson[rt] = update(rson[p], mid + 1, r, x);
    }
    return rt;
}
int query(int u, int v, int l, int r, int i) {
    if (l >= r)
        return l;
    int x = sum[lson[v]] - sum[lson[u]];
    int mid = (l + r) >> 1;
    if (x >= i)
        return query(lson[u], lson[v], l, mid, i);
    else
        return query(rson[u], rson[v], mid + 1, r, i - x);
}
int main() {
    n = read(), m = read(), tot = 0;
    for (int i = 1; i <= n; i++) {
        k = read(),t = read();
        a[i].first = b[i].first = i;
        a[i].second = b[i].second = k * 100000 + 100000 - t;
    }
    sort(b + 1, b + n + 1,cmp());
    root[0] = build(1, n);
    for (int i = 1; i <= n; i++) {
        int p = (int)(lower_bound(b + 1, b + n + 1, a[i],cmp()) - b);
        root[i] = update(root[i - 1], 1, n, p);
    }
    for (int i = 1; i <= m; i++) {
        st = read(),ed = read();
        for (int j = 1; j <= 3; ++j) {
            int ans = query(root[st - 1], root[ed], 1, n, ed - st + 1 - j + 1);
            printf("No.%d %d# %d %d\n", j, b[ans].first, b[ans].second / 100000, 100000 - (b[ans].second % 100000));
        }
    }
    return 0;
}