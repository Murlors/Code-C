#include<bits/stdc++.h>
using namespace std;
const int maxn = 5000005;
int n, p, a[maxn];
int tr[maxn << 2];
inline void down(int k) {
    tr[k << 1] += tr[k];
    tr[k << 1 | 1] += tr[k];
}
void change(int k, int l, int r, int x, int y, int val) {
    if (l == x && y == r) {
        tr[k] += val;
        return;
    }
    if (y <= ((l + r) >> 1))change(k << 1, l, ((l + r) >> 1), x, y, val);
    else if (x > ((l + r) >> 1))change(k << 1 | 1, ((l + r) >> 1) + 1, r, x, y, val);
    else
        change(k << 1, l, ((l + r) >> 1), x, ((l + r) >> 1), val), change(k << 1 | 1, ((l + r) >> 1) + 1, r,((l + r) >> 1) + 1, y, val);
}
int query(int k, int l, int r) {
    if (l == r)return a[l] + tr[k];
    if (tr[k]) down(k);
    return min(query(k << 1, l, ((l + r) >> 1)), query(k << 1 | 1, ((l + r) >> 1) + 1, r));
}
int main() {
    cin >> n >> p;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int x, y, z;
    while (p--) {
        cin >> x >> y >> z;
        change(1, 1, n, x, y, z);
    }
    cout << query(1, 1, n) << "\n";
    return 0;
}