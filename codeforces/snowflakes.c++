#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 8;
int dp[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, 0, sizeof(dp));
    ll curr = 0;
    for(int start = 2; start < 1000; ++start){
        curr = start + 1;
        for(int p = 2; p < 20; ++p){
            if(pow(start, p) < 0) break;
            curr += pow(start, p);
            if(curr >= N) break;
            dp[curr] = 1;
        }
    }

    int tt; cin >> tt;
    while(tt--){
        int temp; cin >> temp;
        cout << (dp[temp] ? "YES" : "NO") << '\n';
    }

    return 0;
}