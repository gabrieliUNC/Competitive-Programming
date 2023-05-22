#include <bits/stdc++.h>
#include <string_view>
using namespace std;

map<string, bool> memo;

static bool endsWith(std::string_view str, std::string_view suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

static bool startsWith(std::string_view str, std::string_view prefix)
{
    return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}

bool can_construct(string target, vector<string> bank){
    if(memo.count(target)) return memo[target];

    if(target == ""){
        memo[target] = true;
        return true;
    }

    for(string e: bank){
        string curr = "";
        if(startsWith(target, e)){
            curr = target.substr(e.length());

            if(can_construct(curr, bank)){
                memo[curr] = true;
                return true;
            }
        }
        else if(endsWith(target, e)){
            curr = target.substr(0, target.length() - e.length());

            if(can_construct(curr, bank)){
                memo[curr] = true;
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

    vector<string> words(n);
    for(int i = 0; i < n; ++i) cin >> words[i];

    cout << boolalpha;
    cout << can_construct(target, words);



    return 0;
}