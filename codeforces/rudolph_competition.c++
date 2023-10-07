#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long int n, m, t, curr, penalty, s; cin >> n >> m >> t;
    map<long long int, pair<long long int, long long int>> mp;
    vector<int> a(m);

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) cin >> a[j];
        sort(a.begin(), a.end());
        curr = 0, penalty = 0, s = 0;
        for(int j = 0; j < m; ++j){
            if(curr + a[j] <= t){
                ++s;
                penalty += curr + a[j];
                curr += a[j];
            }
            else break;
        }
        mp[i] = make_pair(s, penalty);
    }
    int pos = 1;
    s = mp[0].first, penalty = mp[0].second;
    for(int i = 1; i < n; ++i){
        if(mp[i].first == s && mp[i].second < penalty) ++pos;
        if(mp[i].first > s) ++pos;
    }
    cout << pos << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();


    return 0;
}