#include <bits/stdc++.h>
#define ll long long
using namespace std;


main(){
int tt; cin >> tt;
while(tt--){
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    int cnt = 0;
    for (auto& c : s) {
        if (c == '(') {
            ++cnt;
        } else {
            --cnt;
            if (cnt < 0) ++ans, cnt=0;
        }
    }
    cout << ans << '\n';
}



    return 0;
}