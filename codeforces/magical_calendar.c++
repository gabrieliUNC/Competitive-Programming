#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while(t--){
        ll n, r, l = 1, res=0;
        cin >> n >> r;
        if (n<=1){cout << 1 << "\n"; continue;}
        if(n<=r){r=n-1; res = 1;}
        cout << res+((l+r)*(r-l+1)/2) << "\n";
    }




    return 0;
}