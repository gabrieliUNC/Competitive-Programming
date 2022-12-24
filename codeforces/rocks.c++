#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int third[n+1];
    int fourth[n+1];
    for(int i=1; i<=n; ++i){
        cin >> third[i];
    }
    for(int i=1; i<=n; ++i){
        cin >> fourth[third[i]];
    }

    for(int i=1; i<=n; ++i){
        cout << fourth[i] << "\n";
    }
    


    return 0;
}