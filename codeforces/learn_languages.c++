#include <bits/stdc++.h>
using namespace std;

    
const int N = 1e5 + 7;

vector<int> a[N];
bool b[N];
int n, m;

void dfs(int curr){
    if(b[curr])return;
    b[curr] = true;
    for(int i = 0; i < (int)a[curr].size(); ++i)dfs(a[curr][i]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        int k; cin >> k;
        for(int j = 0; j < k; ++j){
            int x; cin >> x; x--;
            a[i].push_back(n + x);
            a[n + x].push_back(i);
        }
        sum += k;
    }
    if(sum == 0){cout << n << '\n'; return 0;}
    for(int i = 0; i < n + m; ++i)b[i] = false;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(!b[i]){
            ++ans;
            dfs(i);
        }
    }

    cout << ans - 1 << '\n';

    return 0;
}

