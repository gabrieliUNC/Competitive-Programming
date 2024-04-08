#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> nums;

int f(int i, ll h, int blue = 1, int green = 2) {
    if(i == size(nums)) return 0;
    int ans = 0;
    
    if(nums[i] < h) ans = max(1 + f(i + 1, h + nums[i] / 2, blue, green), ans);
    else if(blue || green) {
        if(blue) ans = max(ans, f(i, h * 3, 0, green));
        if(green) ans = max(ans, f(i, h * 2, blue, green - 1));
    }

    return ans;
}


void solve() {
    nums.clear();
    int n, h; cin >> n >> h;
    for(int i = 0; i < n; ++i) {
        ll tmp; cin >> tmp;
        nums.push_back(tmp);
    }
    sort(begin(nums), end(nums));

    cout << f(0, h) << '\n';
}


int main() {

    int tt; cin >> tt;
    while(tt--) solve();




    return 0;
}