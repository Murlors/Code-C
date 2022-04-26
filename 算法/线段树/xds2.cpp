#include "bits/stdc++.h"
#define NMAX 100010
using namespace std;
int score[NMAX];
struct xds {
    int l, r, max, maxi;
} tree[NMAX * 4];
int n, m, k, t, a, b;
void build(int i, int bl, int br) {
    tree[i].l = bl;tree[i].r = br;
    if(bl==br) {
        tree[i].max = score[bl];
        tree[i].maxi = bl;
        return;
    }
    int mid = (bl + br) / 2;
    build(i * 2, bl, mid);
    build(i * 2 + 1, mid + 1, br);
    tree[i*2].max>tree[i*2+1].max?tree[i].max=tree[i*2].max,tree[i].maxi=tree[i*2].maxi:tree[i].max=tree[i*2+1].max,tree[i].maxi=tree[i*2+1].maxi;
}
int query(int i, int ql, int qr) {
    if (ql <= tree[i].l && qr >= tree[i].r){
        return tree[i].max;}
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
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> k >> t;
        score[i] = k * 10000 + t;
    }
    build(1, 1, n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        query()
    }
    return 0;
}