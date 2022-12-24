#include <bits/stdc++.h>
using namespace std;


main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<((i%4<=1)!=(j%4<=1));
        }
        cout << "\n";
        }
        
}
return 0;
}
