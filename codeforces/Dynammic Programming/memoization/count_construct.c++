#include <bits/stdc++.h>
#include <string_view>
using namespace std;

map<string, int> memo;

static bool endsWith(std::string_view str, std::string_view suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

static bool startsWith(std::string_view str, std::string_view prefix)
{
    return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}

int count_construct(string target, vector<string> bank){
    if(memo.count(target)) return memo[target];

    if(target == ""){
        return 1;
    }

    int count = 0;

    for(string e: bank){
        string curr = "";
        if(startsWith(target, e)){
            curr = target.substr(e.length());
            count += count_construct(curr, bank);
        }


    }
    memo[target] = count;
    return count;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    string target; cin >> target;

    vector<string> words(n);
    for(int i = 0; i < n; ++i) cin >> words[i];

    cout << count_construct(target, words);



    return 0;
}