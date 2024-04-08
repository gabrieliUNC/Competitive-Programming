#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int mxN = 1e4;

vector<ll> nums = {11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111 };


int solve() {
    ll num; cin >> num;
    ll rem = num / 110;
    // cout << rem << " " << num % 11 << '\n';
    if(rem >= num % 11) return 1;
    return 0;
}

int main() {
    

    // if is multiple of 111 can make it + 1 = ((- 10 * 11) + 111)
    // if is multiple of 1111 can make it + 1 = ((-10 * 111) + 11111)
    // and so on and so forth

    int tt; cin >> tt;
    while(tt--) {
        // ll num; cin >> num;
        // cout << (dp[num] ? "YES\n" : "NO\n") << '\n';
        // cout << "============================\n";
        cout << (solve() ? "YES\n" : "NO\n");
        // cout << "============================\n";
    }



    return 0;
}