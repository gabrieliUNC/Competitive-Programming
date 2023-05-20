#include <bits/stdc++.h>
#include <string_view>
using namespace std;

map<string, bool> memo;
string found = "";

bool can_construct(string target, vector<string> bank){
    if(memo.count(target)) return memo[target];
    cout << target << '\n';

    if(target == found){
        memo[target] = true;
        return true;
    }

    for(string e: bank){
        auto pos = target.find(e);

        if(pos != string::npos){
            string rep = target;

            rep.replace(rep.begin() + pos, rep.begin() + pos + e.size(), string(e.size(), '#'));

            if(can_construct(rep, bank)){
                memo[rep] = true;
                return true;
            }

        }
    }

    memo[target] = false;
    return false;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    string target; cin >> target;

    found = string(target.size(), '#');
    

    vector<string> words(n);
    for(int i = 0; i < n; ++i) cin >> words[i];

    cout << boolalpha;
    cout << can_construct(target, words);



    return 0;
}