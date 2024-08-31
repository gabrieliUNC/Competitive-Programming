#include <bits/stdc++.h>
using namespace std;


void solve() {
    string s, t; cin >> s >> t;
    int cur{0}, j{0}, n = size(t), m = size(s);

    while(cur < n && j < m) {
        // fill wildcard with correct char
        if(s[j] == '?') {
            s[j] = t[cur];
            ++cur;
            ++j;
        }
        // found match
        else if(s[j] == t[cur]) {
            ++cur;
            ++j;
        }
        // no match
        else ++j;
    }

    if(cur == n) {
        cout << "YES\n";
        for(auto& c : s)
            if(c == '?')
                c = 'a';
        cout << s << '\n';
    } else cout << "NO\n";
    
}

int main() {
    int tt; cin >> tt;
    while(tt--)
        solve();



    return 0;
}