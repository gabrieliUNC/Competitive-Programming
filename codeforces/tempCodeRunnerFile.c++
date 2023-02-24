#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;
        vector<ll> curr;
        for(int i = 0; i < n - 1; ++i){
            curr.clear();
            for(int j = 0; j < m; ++j){ ll temp; cin >> temp; curr.push_back(temp); }
            sort(curr.begin(), curr.end());
            for(int j = i; j < m + i; ++j) cout << curr[j % m] << ' ';
            cout << '\n';
        }
        curr.clear();
        for(int i = 0; i < m; ++i){ ll temp; cin >> temp; curr.push_back(temp); }
        sort(curr.begin(), curr.end(), greater<int>());
        for(int e: curr) cout << e << ' ';
        cout << '\n';
    }




    return 0;
}