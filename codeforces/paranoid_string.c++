#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n ; cin >> n;
        string s; cin >> s;
        ll ans = n;
        for(int i=1; i<n; ++i){
            if(s[i]!=s[i-1]){
                ans+=i;
            }
        }
        
        cout << ans << "\n";
        }



    return 0;
}