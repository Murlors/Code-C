#include "bits/stdc++.h"
using namespace std;
__int128 a,b,s;
void input(){
    char ina[101],inb[101];
    cin>>ina>>inb;
    for (int i = 0; ina[i] ; ++i)
        a=a*10+ina[i]-'0';
    for (int i = 0; inb[i] ; ++i)
        b=b*10+inb[i]-'0';
}
void output(){
    int k=0;
    char out[101];
    while (s!=0){
        out[++k]=s%10+'0';
        s/=10;
    }
    for (int i = k; i > 0 ; --i)
        cout<<out[i];
    cout<<endl;
}
int main() {
    input();
    s=a*b;
    output();
    return 0;
}