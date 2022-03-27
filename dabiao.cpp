#include<cstdio>
using namespace std;
int ss[10000010]={0,1,0};
int main() {
    int i;
    printf("{");
    for (i = 2; i * i <= 10000000; i++) {
        if (ss[i] == 0)
            for (int j = i * i; j <= 10000000; j += i)
                ss[j] = 1;
    }
    for (i = 1 ; i < 9999999; ++i) {
        printf("%d,",ss[i]);
    }
    printf("%d}",ss[10000000]);
    return 0;
}