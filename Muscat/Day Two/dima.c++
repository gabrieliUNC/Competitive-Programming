#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    vector<ll> basis;
    vector<ll> ans;
    int n, m; cin >> n >> m;

    ll a[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)cin >> a[i][j];
    }

    ll temp = 0;

    for(int i = 0; i < n; ++i) (temp ^= a[i][0]);

    if(temp){
        cout << "TAK" << '\n';
        for(int i = 0; i < n; ++i) cout << 1 << ' ';
        cout << '\n';
    } else{
        int pos = -1;
        int x = 0;
        for(x; x < n; ++x){
            pos = -1;
            for(int j = 0; j < m; ++j){
                if(a[x][0] != a[x][j]) { pos = j + 1; break; }
            }
            if(pos != -1) break;
        }
        if(pos == -1) cout << "NIE" << '\n';
        else{
            cout << "TAK" << '\n';
            for(int i = 0; i < x; ++i) cout << 1 << ' ';
            cout << pos << ' ';
            for(int i = x + 1; i < n; ++i) cout << 1 << ' ';
            cout << '\n';
        }

    }


    return 0;
}