#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k; cin >> n >> k;
    ll ans = 0;
    string s; cin >> s;
    char pos[k];
    for(int i=0; i<k; ++i)
        cin >> pos[i];
    string npos ("");
    for(int i=0; i<n; ++i){
        bool ok = false;
        for(char c: pos){
            if(c==s[i]){
                ok = true;
                break;
            }
        }
        if(!ok && npos.find(s[i]==-1)){
            npos.push_back(s[i]);
        }
        }
    
    for(int i=0; i<n; ++i){
        string sub ("");
        for(int j=i; j<n; ++j){
            bool run = true;
            sub += s[j];
            for(char c: npos){
            if(sub.find(c)!=-1){
                run = false;
            }
        }
        if(run){ans++;}}
    }
   

    cout << ans << endl;

    return 0;
}