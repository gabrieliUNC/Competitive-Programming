#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int len = s.size();

    int cnt = 0;
    bool flag = 0;
    bool bad = s[0] == '0' ? 1 : 0;
    if(s[0] == '?' ) flag = 1;



    for(char c : s) if(c == '?') ++cnt;

    if(bad){
        cout << 0 << '\n';
        return;
    }

    if(flag){
        cout << pow(10, cnt) - pow(10, cnt - 1) << '\n';
        return;
    }

    else{
        cout << pow(10, cnt) << '\n';
        return;
    }


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    
    while(tt--) solve();


    return 0;
}