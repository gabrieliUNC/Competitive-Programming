#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin >> s;
    bool ok = true;
    for(int i = 2; i < s.size(); ++i){
        if((s[i] - 'A') != (((s[i-1] - 'A') + (s[i-2] - 'A')) % 26)){ok = false; break;}
    }
    if(ok)cout << "YES";
    else cout << "NO";

    return 0;
}