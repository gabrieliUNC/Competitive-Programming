#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 2e3 - 100;
bool p[N];

void solve(){
    int n; cin >> n;
    long long ans = 0;

    cout << ans << '\n';

}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(p, 0, N);

    vector<int> ps;

    for(int i = 1; i < N; ++i){
        string s = to_string(i);
        int src = 0, end = s.size() - 1;
        bool ok = 1;
        while(src != end){
            if(s[src] != s[end]){
                ok = 0;
                break;
            }
            ++src; --end;
        }
        if(!ok) continue;
        ps.push_back(i);
        p[i] = 1;
    }

    cout << ps.size() << '\n';

    // int tt; cin >> tt;
    // while(tt--) solve();




    return 0;
}