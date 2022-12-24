#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    int tt; cin >> tt;
    while(tt--){
        string a; cin >> a;
        vector <int> cnt;
        cnt.push_back(0);
        int ans = 0;
        for(int i=0; i<a.length(); i++){
            if(a[i]=='R'){
                cnt.push_back(i+1);
            }
        }
        cnt.push_back(a.length()+1);
        for(int i=0; i<cnt.size()-1; i++){
                ans = max(ans, cnt[i+1] - cnt[i]);
            }
            cout << ans << '\n';
    }
    return 0;
    }