#include <bits/stdc++.h>
#define ll long long
#define ld long double 
using namespace std;



main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for(int j=1; j<=tt; ++j){
        int n, k; cin >> n >> k;
        int cases[n];
        for(int i=0; i<n; ++i){
            cin >> cases[i];
        }
        int n1 = sizeof(cases) / sizeof(cases[0]);
        sort(cases, cases + n1);
        int cnt = 0;
        int prev = cases[0];
        bool ok = true;
        for(int e: cases){
            if(e==prev){
                cnt++;
                if(cnt>2){
                    ok = false;
                }
            }
            else{
                cnt = 1;
            }
            prev = e;
        }
        if(ok==false || n>(k*2)){
            cout << "Case #" << j << ": " << "NO" << "\n";
        }
        else{
            cout << "Case #" << j << ": " << "YES" << "\n";
        }

    }


    return 0;
}