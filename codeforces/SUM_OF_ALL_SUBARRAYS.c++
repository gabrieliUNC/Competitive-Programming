#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll ans = 0;
ll n; cin >> n;
vector<ll> a(n);
for(int i = 0; i < n; ++i)cin>>a[i];

for(int i = 0; i < n; ++i){
    ans += a[i] * (n - i) * (i + 1);
}

    cout << ans << '\n';


    return 0;
}