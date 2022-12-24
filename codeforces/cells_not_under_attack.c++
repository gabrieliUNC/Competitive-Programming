#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    set <int> r;
    set <int> c;
    int row = n;
    int column = n;
    ll ans = n*n;
    for(int i=1; i<=n; ++i){
        r.insert(i);
        c.insert(i);
    }

    for(int i=0; i<m; ++i){
        int rp, cp; cin >> rp >> cp;
        bool rowExists = r.find(rp) != r.end();
        bool colExists = c.find(cp) != c.end();

        if (rowExists) {
            r.erase(rp);
            column--;
            ans-=row;
        }
        if (colExists) {
            c.erase(cp);
            row--;
            ans-=column;
        }
        cout << ans << " ";
    }
    cout << endl;



    return 0;
}