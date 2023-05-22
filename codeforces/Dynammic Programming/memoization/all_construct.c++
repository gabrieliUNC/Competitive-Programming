#include <bits/stdc++.h>
#include <string_view>
using namespace std;

map<string, vector<vector<string>>> memo;
vector<vector<string>> e;
vector<vector<string>> nxt;

static bool endsWith(std::string_view str, std::string_view suffix)
{
    return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
}

static bool startsWith(std::string_view str, std::string_view prefix)
{
    return str.size() >= prefix.size() && 0 == str.compare(0, prefix.size(), prefix);
}

vector<vector<string>> all_construct(string target, vector<string> bank){

    if(target == ""){
        return e;
    }

    vector<vector<string>> ans;

    for(string e: bank){

        string curr = "";

        if(startsWith(target, e)){
            curr = target.substr(e.length());

            nxt = all_construct(curr, bank);
        
            for(vector<string> v: nxt){
                v.push_back(e);
                for(string x: v) cout << x << '\n';
            }

            for(vector<string> v: nxt) ans.push_back(v);
        }
    }

    return ans;
}



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    e.clear();

    string target; cin >> target;

    vector<string> words(n);
    for(int i = 0; i < n; ++i) cin >> words[i];

    vector<vector<string>> ans = all_construct(target, words);

    for(vector<string> v: ans){
        for(string e: v) cout << e << ' ';
        cout << '\n';
    }
    cout << '\n';



    return 0;
}