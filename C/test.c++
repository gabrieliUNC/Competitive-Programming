#include <bits/stdc++.h>
#include <string>
using namespace std;

const int N = 25;
vector<vector<string>> dp;

bool valid(string s){
    int check = 0;
    for(char c : s){
        if(c == '(') ++check;
        else --check;
        if(check < 0) return 0;
    }
    return check == 0 ? 1 : 0;
}

int main(){
    dp.resize(N);
    dp[0].push_back("()");

    for(int i = 1; i < N; ++i){
        for(string elt : dp[i - 1]){
            dp[i].push_back(elt + "(");
            dp[i].push_back(elt + ")");
        }
    }

    vector<string> ans;

    for(string elt : dp[4]){
        if(valid(elt)) ans.push_back(elt);
    }


    return 0;
}
