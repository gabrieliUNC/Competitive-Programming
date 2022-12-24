#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h, m, s, t1, t2; cin >> h >> m >> s >> t1 >> t2;
    h*=5; t1*=5; t2*=5;
    vector <int> ans;
    ans.push_back(h); ans.push_back(m); ans.push_back(s); ans.push_back(t1); ans.push_back(t2); sort(ans.begin(), ans.end());
    int pos1 = lower_bound(ans.begin(), ans.end(), t1) - ans.begin();
    int pos2 = lower_bound(ans.begin(), ans.end(), t2) - ans.begin();
    cout << (((abs(pos2-pos1)<=1) || (abs(pos2-pos1)==4)) ? "YES" : "NO");
}