#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    int n, up = 0, down = 0; cin >> n;
    vector<ll> a(n);

    for(int i = 0; i < n; ++i) cin >> a[i];

    if(set<ll>(a.begin(), a.end()).size() == 1){
        cout << 0 << '\n';
        return;
    }

    for(int i = 0; i + 1 < n; ++i){
        if(a[i] - a[i + 1] == 0){
            cout << -1 << '\n';
            return;
        }
        if(a[i] < a[i + 1]){
            if(!up) up = a[i + 1] - a[i];
            if(a[i + 1] - a[i] != up){
                cout << -1 << '\n';
                return;
            }
        }

        if(a[i] > a[i + 1]){
            if(!down) down = a[i] - a[i + 1];
            if(a[i] - a[i + 1] != down){
                cout << -1 << '\n';
                return;
            }
        }

    }

    for(int i = 0; i < n; ++i){
        if(a[i] == down){
            if(i + 1 > n){
                cout << -1 << '\n';
                return;
            } 

            if(a[i + 1] != 0){
                cout << -1 << '\n';
                return;
            }
        }
    }

    cout << up + down << ' ' << up << '\n';

    return;


}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--) solve();




    return 0;
}