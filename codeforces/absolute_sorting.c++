#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];

    

        ll high = 1e9 + 8, low = 0;

        for(int i = 0; i + 1 < n; ++i){
            
            if(a[i] < a[i + 1]){
                high = min(high, (a[i] + a[i + 1]) / 2);
            }
            else if(a[i] > a[i + 1]){
                low = max(low, (a[i] + a[i + 1] + 1) / 2);
            }
        }
        if(low <= high)cout << low << '\n';
        else cout << -1 << '\n';
    }

    return 0;
}