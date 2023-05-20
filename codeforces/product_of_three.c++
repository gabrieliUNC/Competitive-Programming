#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;

    while(tt--){
        ll n; cin >> n;

        int i = 2;
        ll div_1 = -1;
        ll div_2 = -1;


        while(i < 5e4){
            div_1 = gcd(n, i);
            ++i;
            if(div_1 > 1) break;
        }

        if(div_1 < 2){
            cout << "NO" << '\n';
            continue;
        }

        n /= div_1;

        while(i < 5e4){
            div_2 = gcd(n, i);
            ++i;
            if(div_2 > 1 && div_2 != div_1) break;
        }

        if(div_2 < 2){
            cout << "NO" << '\n';
            continue;
        }

        n /= div_2;

        if(n == 1 || div_1 == n || div_2 == n){
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';
        cout << div_1 << ' ' << div_2 << ' ' << n << '\n';

    }





    return 0;
}