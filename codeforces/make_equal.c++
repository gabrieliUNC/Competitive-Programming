#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n; char tag; cin >> tag; string s; cin >> s; bool ok = true;
        vector<int> ans;
        for (char c: s)
            if (c!=tag) ok = false;
        if (!ok){
            for(int i=1; i<n+1;++i){
                ok = true;
                for(int j=i; j<n+1;++j){
                    ok &= (s[j-1]==tag);
                    j+=i-1;
                }
                if(ok){
                    ans.push_back(i);
                    break;
                }
            }
            if(!ok){
                ans.push_back(n);
                ans.push_back(n-1);
            }
        }
        cout << ans.size()<<"\n";
        for(int e: ans){
            cout << e << " ";
        }
        cout << "\n";

    }



    return 0;
}