#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e7 + 8;
bool p[inf];

void sieve(int x){
    p[0] = 1;
    for(int i = 3; i * i <= x; i += 2){
        if(p[i / 2] == 0){
            for(int j = 3 * i; j <= x; j += 2 * i){
                p[j / 2] = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    sieve(n + 7);

    vector<int> ans(n + 3, 1);
    if(n >= 3){
    for(int i = 3; i <= n + 3; ++i){
        if(p[i / 2] == 0 && i % 2 == 1) ans[i] = 1;
        else ans[i - 2] = 2;
    }
    cout << 2 << '\n';
    }
    else{
        cout << 1 << '\n';
    }
    for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';



    return 0;
}