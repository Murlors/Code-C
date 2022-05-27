#include "bits/stdc++.h"
#define NMAX 1000010
using namespace std;
struct xds {
    int l, r, cover, lazy;
} tree[NMAX * 4];
int n, m, q, a, b, s, t;
void build(int i, int bl, int br) {
    tree[i].l = bl;tree[i].r = br;
    tree[i].cover = 0;tree[i].lazy = 0;
    if (bl == br) return;
    int mid = (bl + br) / 2;
    build(i * 2, bl, mid);
    build(i * 2 + 1, mid + 1, br);
}
void pushdown(int i, int pl, int pr) {
    int mid = (pl + pr) / 2;
    tree[i * 2].cover = mid - pl + 1;
    tree[i * 2].lazy = 1;
    tree[i * 2 + 1].cover = pr - mid;
    tree[i * 2 + 1].lazy = 1;
    tree[i].lazy = 0;
}
void update(int i, int ul, int ur) {
    if (ul <= tree[i].l && ur >= tree[i].r) {
        tree[i].cover = tree[i].r - tree[i].l + 1;
        tree[i].lazy = 1;
        return;
    }
    if (tree[i].lazy) pushdown(i, tree[i].l, tree[i].r);
    int mid = (tree[i].l + tree[i].r) / 2;
    if (mid >= ul)update(i * 2, ul, ur);
    if (mid < ur)update(i * 2 + 1, ul, ur);
    tree[i].cover = tree[i * 2].cover + tree[i * 2 + 1].cover;
}
int query(int i, int ql, int qr) {
    if (ql <= tree[i].l && qr >= tree[i].r)
        return tree[i].cover;
    if (tree[i].lazy) pushdown(i, tree[i].l, tree[i].r);
    int ans = 0;
    int mid = (tree[i].l + tree[i].r) / 2;
    if (mid >= ql) ans += query(2 * i, ql, qr);
    if (mid < qr) ans += query(2 * i + 1, ql, qr);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        update(1, a, b);
    }
    for (int i = 0; i < q; ++i) {
        cin >> s >> t;
        cout << t - s + 1 - query(1, s, t) << '\n';
    }
    return 0;
}