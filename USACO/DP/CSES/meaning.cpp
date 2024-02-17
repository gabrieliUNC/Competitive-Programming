#include <bits/stdc++.h>
using namespace std;


const int mxN = 33;
int dp[mxN];
const int MOD = 1e9 + 7;

int main(){
    string s; int n; cin >> n >> s;
    vector<pair<string, int>> words(n);
    for(int i = 0; i < n; ++i){
        string tmp1; int tmp2; cin >> tmp1 >> tmp2;
        words[i] = {tmp1, tmp2};
    }
    
    memset(dp, 0, sizeof(dp)); dp[0] = 1;


    for(int i = 1; i <= s.size(); ++i){
        for(auto word : words){
            int len = (int)word.first.size();
            if(len <= i){
                string curr = s.substr(i - len, len);
                if(word.first == curr){
                    dp[i] += dp[i - len] * word.second;
                    dp[i] %= MOD;
                }
            }
        }
    }

    for(int i = 0; i <= s.size(); ++i) cout << dp[i] << ' ';
    cout << '\n';

    cout << max(dp[s.size()], 1) << '\n';



    return 0;
}