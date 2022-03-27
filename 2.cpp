#include "bits/stdc++.h"
using namespace std;
long long n;
__int128 arr[70];
__int128 qpow(__int128 a, __int128 n) {
    int ans = 1;
    while (n) {
        if (n & 1)ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}
int main() {
    for (int i = 1; i <= 64; ++i)
        arr[i]= qpow(2,i);
    while(cin>>n){
        int i=1;
        while(arr[i]<n)i++;
        long long ans=(arr[i]-n)<(n-arr[i-1])?(arr[i]-n):(n-arr[i-1]);
        cout<<ans<<endl;
    }
    return 0;
}