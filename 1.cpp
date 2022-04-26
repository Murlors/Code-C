#include <bits/stdc++.h>
using namespace std;
string op;
int main() {
    while(cin>>op,op!="QUIT"){
        if(op=="IN"){
            in();
        }else if(op=="LIST"){
            blist();
        }else if(op=="OUT"){
            out();
        }
    }
    cout<<"GOOD BYE!"<<"\n";
    return 0;
}