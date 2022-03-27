#include "bits/stdc++.h"
using namespace std;
int n,p[6];
map<int,int> m;
set<int> s;
int main() {
    while (cin >> n && n != 0) {
        m.clear();s.clear();
        for (int i = 0; i < n; ++i) {
            cin >> p[0] >> p[1] >> p[2];
            memcpy(p + 3, p, 3 * sizeof(int));
            int j = 0, f, e;
            while (p[j] != 1)j++;
            f = p[j + 1];e = p[j + 2];
            m[f] = e;
            s.insert(e);
        }
        int ans = 1;
        if (m.size() != n || s.size() != n) ans = 0;
        else {
            s.clear();
            int front = m.begin()->first, next = m.begin()->second;
            s.insert(front);
            do {
                s.insert(next);
                map<int, int>::iterator iter = m.find(next);
                if (iter == m.end()) {ans = 0;break;}
                next = iter->second;
            } while (s.find(next) == s.end());
            if (s.size() != n)ans = 0;
        }
        if (ans == 1)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}