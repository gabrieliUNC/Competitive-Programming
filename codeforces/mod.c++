#include <bits/stdc++.h>
#define ll long long
using namespace std;


int solve(){
    int n; cin >> n;
    vector <ll> a;
    for(int i=0; i<n; ++i){
        ll temp; cin >> temp;
        a.push_back(temp);
    }
    
    sort(a.begin(), a.end());
    ll prev = a[0];
    bool ok = false, okay=false;
    for(int i=1; i<n; ++i){
        if (a[i]==1 || prev==1) {ok=true;}
        if((a[i]-prev)==1) {okay=true;}
        prev = a[i];
    }

    cout << ((ok && okay) ? "NO" : "YES") << "\n";
    return 0;
}




main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}