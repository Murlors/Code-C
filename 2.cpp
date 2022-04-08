#include "bits/stdc++.h"
using namespace std;
int n,k,x;
vector<int> arr;
int main() {
    cin >> n >> k >> x;
    int sum = 0, cnt = 0,tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        arr.emplace_back(tmp);
    }
    for (int i = n - 1; i >= 0; --i) {
        if (cnt < k) {
            if(arr[i]>x){
                int m=arr[i]/x;
                if(cnt+m>k){
                    arr[i]-=(k-cnt)*x;
                    cnt=k;
                }else {
                    arr[i]-=m*x;
                    cnt+=m;
                }
            }
        }
    }
    sort(arr.begin(), arr.end());
    for (int i = n-1; i >=0 ; --i) {
        if(k==cnt){
            sum+=arr[i];
        }else{
            cnt++;
        }
    }
    cout<<sum<<endl;
    return 0;
}