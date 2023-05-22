#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> dp;
vector<string> null;

int main(){
    null.clear();

    string target; cin >> target;

    dp.resize(target.size() + 1);

    for(int i = 0; i <= target.size(); ++i) dp[i] = null;

    int n; cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; ++i) cin >> words[i];

    for(int i = 0; i <= target.size(); ++i){
        for(string word : words){
            if(target.substr(i, word.size()) == word && i + word.size() <= target.size()){
                for(string e: dp[i]) dp[i + word.size()].push_back(e);
                dp[i + word.size()].push_back(word);
            }
        }
    }

    for(string e: dp[target.size()]) cout << e << ' ';
    cout << '\n';

    return 0;
}