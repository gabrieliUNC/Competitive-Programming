#include <bits/stdc++.h>
using namespace std;

vector<int> dp;

int main(){

    string target; cin >> target;

    dp.resize(target.size() + 1);
    
    for(int i = 0; i <= target.size(); ++i) dp[i] = 0;
    dp[0] = 1;

    int n; cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; ++i) cin >> words[i];

    for(int i = 0; i <= target.size(); ++i){
        for(string word : words){
            if(target.substr(i, word.size()) == word && i + word.size() <= target.size()){
                dp[i + word.size()] += dp[i];
            }
        }
    }

    cout << dp[target.size()] << '\n';




    return 0;
}