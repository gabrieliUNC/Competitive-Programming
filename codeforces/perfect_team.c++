#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;


main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tt; cin >> tt;
    while(tt--){
        ll a, b, c; cin >> a >> b >> c;
        ll ans = min(a, b);
        if(ans<=c){
            cout << ans << endl;
        }
        else{
            ans = c;
            a-=c;
            b-=c;
            ll temp = min(a,b);
            if(abs(a-b)>((a+b)/3)){
                ans+=temp;
                cout << ans << endl;
            }
            else{
                ans+= ((a+b) / 3);
                cout << ans << endl;
            }
        }
    }


    return 0;
}