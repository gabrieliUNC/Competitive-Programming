#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll const filled = 50;
ll dp[filled];

int main(){
    for(ll i=0; i<filled; ++i){
        dp[i] = pow(2, i);
    }
    int n; cin >> n;
    int i=filled-1;
    string ans ("");
    bool start = false;
    while(i>=0){
        if(n>=dp[i]){
            start = true;
            ans.append(to_string(1));
            n-=dp[i];
        }
        else if(start){
            ans.append("0");
        }
        i--;
    }
    cout << ans;
    return 0;

}