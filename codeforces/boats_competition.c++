#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


int solve(){
    int n;
    cin >> n;
    vector<int> w(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++w[x];
    }

    int res = 0;
    for (int sum = 2; sum <= 2 * n; ++sum) {
        int temp = 0;
        for (int i = 1; i < (sum + 1) / 2; ++i) {
            if (sum - i > n) continue;
            temp += min(w[i], w[sum - i]);
        }
        if (sum % 2 == 0) temp += w[sum / 2] / 2;
        res = max(res, temp);
    }
    return res;
}

main(){
    ll t; cin >> t;
    while(t--){
    cout << solve() << endl;
    }


    return 0;
}
