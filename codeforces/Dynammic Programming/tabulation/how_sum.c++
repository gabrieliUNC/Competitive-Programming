#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e3 + 7;


int main(){
    vector<vector<int>> dp;

    dp.clear();
    dp.resize(N);

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    dp[0].push_back(0);

    for(int i = 0; i < N; ++i){
        if(dp[i].size()){
            for(int e : a){
                if(i + e < N && !dp[i + e].size()){
                    for(int x: dp[i]) if(x != 0) dp[i + e].push_back(x);
                    dp[i + e].push_back(e);
                }
            }
        }
    }

    int target; cin >> target;

    for(int e: dp[target]) if(e != 0) cout << e << ' ';
    cout << '\n';

    


    return 0;
}