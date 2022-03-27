#include<bits/stdc++.h>
using namespace std;
int main() {
    int r,n;
    char c;
    scanf("%d", &r);
    while (r--) {
        int sum = 0;
        stack<char>Q;
        scanf("%d", &n);
        getchar();//\n
        for (int i = 1; i <= n; i++) {
            scanf("%c", &c);
            if (Q.empty()) Q.push(c);
            else if (c == ')') {
                while (!Q.empty()) Q.pop();
                sum++;
            } else {
                if (Q.size() == 1 && Q.top() == ')') Q.push(c);
                else if (Q.size() != 1)  Q.push(c);
                else {//Q.top()='('
                    sum++;
                    Q.pop();
                }
            }
        }
        printf("%d %d\n", sum, Q.size());
        getchar();
    }
    return 0;
}