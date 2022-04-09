#include "bits/stdc++.h"
using namespace std;
int n, m, s[5001], cnt;
bool flag[5001];
long long sum;
struct t {
    int x, y, z;
} tmp;
vector<t> arr;
bool cmp(const t a, const t b) {
    return a.z < b.z;
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    if (n - 1 > m) {
        goto error;
    }
    for (int i = 0; i < m; ++i) {
        cin >> tmp.x >> tmp.y >> tmp.z;
        if (!flag[tmp.x])flag[tmp.x] = true;
        if (!flag[tmp.y])flag[tmp.y] = true;
        arr.emplace_back(tmp);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 1; i <= n; ++i) s[i] = i;
    for (int i = 0; i < m; ++i) {
        if (merges(arr[i].x, arr[i].y)) sum += arr[i].z;
        if (cnt == n - 1) break;
    }
    if (cnt < n - 1) goto error;
    cout << sum << endl;
    return 0;
    error:
    cout << "orz" << endl;
    return 0;
}