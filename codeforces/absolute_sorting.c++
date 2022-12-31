#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll>a(n);
        bool inc = true, dec = true;
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
            if(i){
                if(a[i]<a[i-1])inc=false; 
                if(a[i]>a[i-1])dec=false;
            }
        }
        if(inc){
            cout << 0 << '\n'; 
            continue;
            }
    
        if(dec){
            cout << *max_element(a.begin(), a.end())+1 << '\n';
            continue;
            }

        ll max = *max_element(a.begin(), a.end());
        ll min = *min_element(a.begin(), a.end());
        ll alt = ceil(((double)(max + min))/2.0);

        for(int i = 0; i < n; ++i)a[i] = abs(a[i]-alt);
        bool ok = true;
        for(int i = 0; i < n; ++i){
            if(i){
                if(a[i]<a[i-1]){cout << -1 << '\n'; 
                ok = false;
                }
                }
            }
        if(ok)cout << alt << '\n';
    }

    return 0;
}