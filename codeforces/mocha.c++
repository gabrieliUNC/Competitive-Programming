#include <bits/stdc++.h>
using namespace std;

main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; string s; cin >> s;
        if(s[0]=='?'){
            s[0] = s[1]=='B' ? 'R' : 'B';
        }
        for(int i=1; i<n; ++i){
            if(s[i]=='?'){
                char prev = s[i-1];
                char next = i+1 < n ? s[i+1] : '/';
                if(prev=='B'){
                    s[i] = 'R';
                }
                else if(prev=='R'){
                    s[i] = 'B';
                }
            }
        }
        cout << s << "\n";
    }
}