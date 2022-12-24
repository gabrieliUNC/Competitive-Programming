#include <bits/stdc++.h>
#define ll long
#define ld long double
#define pb push_back
#define all(x) begin(x), end(x)
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    for(char c: s){
        ans = max((int)c - 96, ans);
    }
    cout << ans << "\n";
    }

    return 0;
}