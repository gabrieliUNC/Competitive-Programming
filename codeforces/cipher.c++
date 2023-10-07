#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    char key = s[0];
    string ans = "";

    int i = 1;
    while(i < n){
        if(s[i] == key){
            ans += s[i];
            if(i + 1 < n) ++i, key = s[i];
        }
        ++i;
    }

    cout << ans << '\n';
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;

    while(tt--) solve();


    return 0;
}