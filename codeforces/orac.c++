#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> q(n);
        bool ok = false;
        ll last = 10e9 + 8;
        for(int i=0; i<n; ++i){
            cin >> q[i];
            if(q[i] > last)ok = true;
            last = min(last, q[i]);
        }
        if(!ok){cout << 1 << '\n'; continue;}
        
        

    }




    return 0;
}