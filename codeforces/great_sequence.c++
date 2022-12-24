#include <bits/stdc++.h>
#include <unordered_map>
#define ll long long
using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll n, x, ans=0; cin >> n >> x;
        map<ll, ll> m;
        for(int i=0; i<n; i++){
            ll temp; cin >> temp;
            m[temp]++;
        }

        for(auto i=m.begin(); i!=m.end(); i++){
            ll temp = (*i).first; ll comp = (*i).second;
            if(comp!=0){
                temp*=x;
                if(m[temp]!=0){
                    if(m[temp]>=comp){
                        m[temp]-=comp;
                    }
                    else{
                        ans+=(comp-m[temp]);
                        m.erase(temp);
                    }
                }
                else{
                    ans+=comp;
                }
            }
        }
        
        cout << ans << "\n";

    }

    return 0;
}