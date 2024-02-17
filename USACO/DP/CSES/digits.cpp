#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 7;

unordered_map<int, int> dp;

int remove(int curr){
    if(curr == 0) return dp[curr] = 0;
    if(dp.count(curr)) return dp[curr];

    int ans = inf;

    int target = curr;
    while(curr){
        if(curr % 10) ans = min(ans, 1 + remove(target - (curr % 10)));
        curr /= 10;
    }

    return dp[target] = ans;
}

int main(){
    int target; cin >> target;
    cout << remove(target) << '\n';

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// const int inf = 1e9 + 7;


// int main(){
//     int target; cin >> target;
//     int dp[target + 1];
//     memset(dp, inf, sizeof(dp));
//     dp[0] = 0;
//     for(int i = 1; i <= target; ++i){
//         for(auto c : to_string(i)){
//             dp[i] = min(dp[i], dp[i -  (c - '0')] + 1);
//         }
//     }

//     cout << dp[target] << '\n';

//     return 0;
// }