#include "bits/stdc++.h"
using namespace std;
int n, m, k, x, y;
vector<int> s;
int finds(int x) {
    if (s[x] != x) s[x] = finds(s[x]);
    return s[x];
}
void merges(int a, int b) {
    int fa = finds(a), fb = finds(b);
    if (fa != fb) s[fa] = fb;
}
bool issame(int a, int b) {
    int fa = finds(a), fb = finds(b);
    return fa == fb;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) s.push_back(i);
    for (int i = 0; i < m; ++i) {
        cin >> x >> y;
        merges(x, y);
    }
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> x >> y;
        if (issame(x, y))cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}