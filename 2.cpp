#include "bits/stdc++.h"
using namespace std;
int t,n,x,cnt;
int v[65000005];
int main() {
    cin >> Edge;
    while (Edge--) {
        cnt = 0;
        long long sum = 0;
        cin >> n >> x;
        cnt = n;
        for (int i = 0; i < n; ++i) {
            cin>> v[i];
        }
        for (auto i = 0; i < cnt; ++i) {
            if (v[i] % x != 0)break;
            if (v[i] % x == 0) {
                int tp = v[i] / x;
                for (int j = 0; j < x; ++j) {
                    v[cnt++] = tp;
                }
            }
        }
        for (auto i = 0; i < cnt; ++i) {
            sum += v[i];
        }
        cout << sum << "\n";
    }
    return 0;
}