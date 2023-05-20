#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        ll l, r, x, src, dest; cin >> l >> r >> x >> src >> dest;

        if(src == dest){
            cout << 0 << '\n';
            continue;
        }

        if(abs(src - dest) >= x){
            cout << 1 << '\n';
            continue;
        }
        if(r - max(src, dest) >= x || min(src, dest) - l >= x){
            cout << 2 << '\n';
            continue;
        }

        if((r - dest >= x && src - l >= x) || (r - src >= x && dest - l >= x)){
            cout << 3 << '\n';
            continue;
        }

        cout << -1 << '\n';


    }



    return 0;
}