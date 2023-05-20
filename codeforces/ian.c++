#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    while(tt--){
        ll n, sum = 0; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if(i % 2) sum += a[i];
            else sum -= a[i];
        }

        if(n % 2 == 1 || sum >= 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';

    }




    return 0;
}