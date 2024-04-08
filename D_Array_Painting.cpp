#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans = 0; cin >> n;
    vector<int> s;
    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        if(tmp == 0) s.push_back(tmp);
        else {
            if(tmp == 2) {
                while(size(s) && s.back() != 0) s.pop_back();
                s.push_back(tmp);
            } if(tmp == 1) {
                while(size(s) && s.back() == 1) s.pop_back();
                if(size(s) && s.back() == 2) continue;
                s.push_back(tmp);
            }
        }
    }

    n = size(s);
    int l = 0;
    
    while(l < n) {
        int r = l + 1;
        bool ok = (s[l] == 2), ok2 = 0;

        while(r < n) {
            if(r - 1 > l && s[r - 1] == 0) ok2 = 1;
            if(s[r] == 2) ok = 1;

            
            if(!((!ok2) && (ok || s[l] != 0 || s[r] != 0))) break;
            r++;
        }
        l = r;
        ans++;
    }

    

    cout << ans << '\n';






    return 0;
}