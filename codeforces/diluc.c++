#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

pair<int, int> r(int x, int y){
    int g = __gcd(x, y);
    x /= g;
    y /= g;

    return make_pair(x, y);
}


void solve(){
    int n; cin >> n; string s; cin >> s;


    map<pair<int, int>, int> m;

    int d = 0, k = 0;

    for(char c: s){
        if(c == 'D') ++d;
        else ++k;
        cout << ++m[r(d, k)] << ' ';
    }

    cout << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;

    while(tt--) solve();



    return 0;
}