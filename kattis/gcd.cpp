#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    vector<int> t; t.push_back(a[0]);

    for(int i = 1; i < n; ++i){
        if(a[i] != t.back()) t.push_back(a[i]);
    }

    int ans = 0;
    n = t.size();

    for(int i = 1; i <= 100; ++i){
        
        vector<int> p(n + 1, 0);
        bool ok = 0;
        for(int j = 1; j <= n; ++j){
            int g = gcd(p[j - 1], t[j - 1]);
            if(!(g % i)) {
                p[j] = g;
                if(p[j] == i){
                    ok = 1;
                    break;
                }
            }
            
        }
        if(ok) ++ans;
    }

    

    cout << ans << '\n';

    return 0;
}