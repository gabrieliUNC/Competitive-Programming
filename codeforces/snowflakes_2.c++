#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e18;
int dp[N];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, 0, sizeof(dp));
    ll curr = 0;
    for(int start = 2; start < 1e7; ++start){
        curr = start + 1;
        for(int p = 2; p < 20; ++p){
            if(pow(start, p) < start) break;
            curr += pow(start, p);
            if(curr >= N) break;
            dp[curr] = 1;
        }
    }

    return 0;
}