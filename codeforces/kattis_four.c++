#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p, surplus = 0; cin >> n >> p;
    unordered_map<int, pair<int, int>> mp;
    double food = 0.0, ans = 1e7;


    for(int i = 0; i < n; ++i){
        int curr, expires; cin >> curr >> expires;
        food += curr; 
        ++surplus;
        if((int) food == 0) break;

        if(curr) mp[i + expires].first += curr, mp[i + expires].second++;   
        if(mp.count(i)) food -= mp[i].first, surplus -= mp[i].second;

        double temp = (food / ((double) (p)));
        temp /= max((double) surplus, 1.0);
        ans = min(ans, temp);
    }

    if(food == 0.0) cout << -1 << '\n';
    else cout << ans << '\n';

    return 0;
}