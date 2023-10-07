#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e7;
int small[mxN], num[mxN];
const long long mod =9302023;

int main(){
    string s; cin >> s;
    vector<string> words{
        "one",
        "two",
        "zero",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
    int n = s.size();
    for(int i = 1; i <= n; ++i) small[i] = i;
    small[0] = 0;
    memset(num, 0, sizeof(num));
    num[0] = 1;

    for(int i = 1; i <= n; ++i){
        small[i] = small[i - 1] + 1;
        for(auto word : words){
            if (i - ((int) word.size()) >= 0) {
                
                string curr = s.substr(i-word.size(), word.size());
                if (curr == word) {
                    small[i] = min(small[i], small[i - word.size()] + 1);
                }
                
            }
        }
        if (small[i - 1] == small[i] - 1) {
            num[i] += num[i-1];
            if (num[i] >= mod) num[i] -= mod;
        }
        for (auto word : words) {
            if (i - ((int) word.size()) >= 0) {
                string curr = s.substr(i-word.size(), word.size());
                if (curr == word && small[i - word.size()]+1 == small[i]) {
                    num[i] += num[i - word.size()];
                    if (num[i] >= mod) num[i] -= mod;
                }
            }
        }

    }

    cout << small[n] << '\n';
    cout << num[n] << '\n';
    return 0;
}