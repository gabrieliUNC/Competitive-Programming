#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){

    return ((ld)(a.first/a.second) < (ld)(b.first/b.second));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    ll in[n]; ll sum[n];
    for(int i=0; i<n; ++i) cin >> in[i];
    for(int i=0; i<n; ++i) cin >> sum[i];
    vector<pair<ll, ll>> v(n);
    for(int i=0; i<n; ++i) v[i] = {sum[i], in[i]};

    while(k>0){
        sort(v.begin(), v.end(), cmp);
        v[0].first++;
        k--;
    }
    
    sort(v.begin(), v.end(), cmp);
    cout << (v[0].first/v[0].second) << "\n";




    return 0;
}