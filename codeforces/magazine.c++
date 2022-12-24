#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int in[n];
        int pos[n];
        int ans = 0;
        int i = 0;
        for(char c: s){
            pos[i] = (c - '0');
            i++;
        }
        for(int i=0; i<n; ++i){
            cin >> in[i];
        }
        for(int i=1; i<n; ++i){
            if((pos[i]==1 && pos[i-1]==0) && (in[i-1] > in[i])){
                ans+=in[i-1];
                pos[i]=0;
            }
            else if((pos[i]==1 && pos[i-1]==1) || (pos[i]==1 && pos[i-1]==0) && (in[i-1] < in[i])){
                ans+=in[i];
            }
        }


        cout << ans << "\n";
    }




    return 0;
}