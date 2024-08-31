#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve() {
    int n; string s;
    cin >> n >> s;

    unordered_set<string> u;
    for(int i = 2; i <= n; ++i) {
        u.insert(s.substr(0, i - 2) + s.substr(i));
    }
    cout << size(u) << '\n';
}

int main() {
    int tt; cin >> tt;
    while(tt--)
        solve();




    return 0;
}