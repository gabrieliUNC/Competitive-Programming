#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll solve(){
    int n; cin >> n;
    ll ans = 0;
    vector<int> a(n);
    for(int i = n - 1; i >= 0; --i) cin >> a[i];

    for(int i = 1; i < n; ++i){
        if(a[i] > a[i - 1]){
            a[i - 1] = (a[i] - 1) / a[i - 1];
            ans += a[i - 1];
            a[i] /= a[i - 1] + 1;
        } 
    }

    return ans;

}

int main(){
    int tt; cin >> tt;
    while(tt--) cout << solve() << '\n';


    return 0;
}