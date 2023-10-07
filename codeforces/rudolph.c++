#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n; cin >> n;
    int ans = 0;
    while(n--){
        int a, b; cin >> a >> b;
        if (a > b) ++ans;
    }
    return ans;
}

int main(){

    int tt; cin >> tt;
    while(tt--) cout << solve() << '\n';


    return 0;
}