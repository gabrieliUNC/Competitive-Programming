#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll>a;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    for(ll i = 1; i*i <= n; ++i){
        if(n%i==0){
            a.push_back(i);
            if(n/i!=i)a.push_back(n/i);
        }
    }
    sort(a.begin(), a.end());
    if(a.size() < k)cout << -1 << '\n';
    else cout << a[k-1] << '\n';

    return 0;
}