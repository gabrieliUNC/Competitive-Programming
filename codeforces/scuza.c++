#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    vector<ll> height;
    vector<ll> sum;
    while(t--){
        ll n, q; cin >> n >> q;
        height.resize(n);
        sum.resize(n);
        ll h = 0;
        for(int i=0; i<n; ++i){
            ll temp; cin >> temp;
            h = max(h, temp);
            height[i] = h;
            sum[i] = i==0 ? temp : sum[i-1]+temp;
        }
        for(int i=0; i<q; ++i){
            ll temp; cin >> temp;
            auto pos = upper_bound(begin(height), end(height), temp) - begin(height);
            cout << (pos==0 ? 0 : sum[pos-1]) << ' ';
        }
        cout << "\n";
    }



    return 0;
}