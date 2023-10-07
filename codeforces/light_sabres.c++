#include <bits/stdc++.h>
using namespace std;


bool solve(){
    
    int n, m; cin >> n >> m;

    vector<int> jedis(n);
    map<int, int> colors;

    for(int i = 0; i < n; ++i) cin >> jedis[i];
    for(int i = 1; i <= m; ++i){
        int cnt; cin >> cnt;
        for(int j = 0; j < cnt; ++j) colors[i]++;
    }


    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            map<int, int> curr; 

            for(int k = i; k <= j; ++k){
                curr[jedis[k]]++;
            }

            if(curr == colors) return 1;
            
        }
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cout << (solve() ? "YES" : "NO") << '\n';

    return 0;
}