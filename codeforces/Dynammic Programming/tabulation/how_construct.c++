#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector<string> dp;

int main(){
    dp.resize(N);
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    for(int i = 0; i < N; ++i) dp[i] = "";
    dp[0] = "";

    int curr = 1;

    for(int i = 0; i < N; ++i){
        if(curr > N) break;
        for(string e : a){
            if(curr < N) dp[curr] = dp[i] + e;
            ++curr;
        }
    }

    string target; cin >> target;

    int ans = 0;

    for(string e: dp) if(e == target) ++ans;

    cout << ans << '\n';

    return 0;
}