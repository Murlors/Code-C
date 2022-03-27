
#include "bits/stdc++.h"

using namespace std;
int t,n,k,cnt;
string str;
int pp(int i) {
    int l = i;
    stack<char> s;
    s.push('\0');
    while (l <= str.length()) {
        char ch = str[l];
        if (ch == ')') {
            if (s.top() == '(') {
                s.pop();
                l++;
            } else return 0;
            if (s.top() == '\0') {
                cnt++;
                return l - i;
            }
        } else if (ch == '(') {
            s.push(ch);
            l++;
        } else {
            return 0;
        }
    }
}
int hw(int i) {
    for (int l = i + 2; l <= str.length(); l++) {
        if (str[l] == str[i]) {
            cnt++;
            return ++l;
        }
        else if (str[l] == str[i + 1]) {
            continue;
        } else {
            return i;
        }
    }
}
int main() {
    cin >> t;
    while (t--) {
        cin>>n>>str;
        cnt=0;
        int i=0;
        while(true){
            if(i>=str.length())break;
            int tmp=pp(i);
            if(tmp==0){
                if(str[i]==str[i+1]){
                    cnt++;
                    i+=2;
                }else if(str.length()-i>=2) {
                    int s = hw(i);
                    if (s == i)break;
                    else i = s;
                }else break;
            }else {
                i+=tmp;
            }
        }
        cout<<cnt<<" "<<str.length()-i<<endl;
    }
    return 0;
}