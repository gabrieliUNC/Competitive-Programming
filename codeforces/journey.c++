#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 7;
vector<int> mp[N];
long double dp[N];

void dfs(int v, int par = -1){

    int child = mp[v].size() - 1 + (v == 1);

    for(int u : mp[v]){
        if(u != par) dfs(u, v), dp[v] += ((1 + dp[u]) / child);
    }

}

int main(){
    int n; cin >> n;

    for(int i = 0; i < n - 1; ++i){
        int a, b; cin >> a >> b;

        mp[a].push_back(b), mp[b].push_back(a);
    }


    dfs(1);


    cout << setprecision(11) << fixed << dp[1] << '\n';


    return 0;
}