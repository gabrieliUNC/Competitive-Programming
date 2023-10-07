#include <bits/stdc++.h>
#include <set>
using namespace std;

set<int> s;
 
const int N = 1e7 + 5;
int ans[N];
 
int main(){
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) s.insert(i);

    for (int i = 0; i < m; ++i){   
        int l, r, x; cin >> l >> r >> x;

        set<int>::iterator low = s.lower_bound(l);
        set<int>::iterator high = s.upper_bound(r);

        for (set<int>::iterator it = low; it != high; it++) if(x != *it) ans[*it] = x;
        
        s.erase(low, high);
        s.insert(x);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}