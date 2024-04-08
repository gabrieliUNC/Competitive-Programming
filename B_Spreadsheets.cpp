#include <bits/stdc++.h>
#define int long long
using namespace std;



string i_to_letters(int num) {
    string letters = "";
    int k = 26, l = 1;
    while(k < num) {
        num -= k;
        k *= 26;
        ++l;
    }

    for (int i = 0; i < l; ++i) {
        k /= 26;
        for (int j = 0; j < 26; j++)
        if (num <= k) {
                letters +=  (char ('A' + j));
                break;
        } else num -= k;
	}
    return letters;
}

int letters_to_i(string letters) {
    int num = 0, n = size(letters);

    for(int i = n - 1; i >= 0; --i) {
        num += pow(26, n - (i + 1)) * ((letters[i] - 'A') + 1);
    }

    return num;
}

void solve() {
    string s; cin >> s;

    if(s[0] == 'R' && isdigit(s[1]) && find(s.begin(), s.end(), 'C') != s.end()) {
        int i = 1, num = 0;
        while(s[i] != 'C') {
            num = num * 10 + (s[i] - '0');
            ++i;
        }

        int row = num;

        ++i;
        num = 0;
        while(i < size(s)) {
            num = num * 10 + (s[i] - '0');
            ++i;
        }
        // cout << num << '\n';
        string col = i_to_letters(num);

        cout << col + to_string(row) << '\n';
    } 

    else {
        int i = 0; string letters = "";
        while(!isdigit(s[i])) letters += s[i++];

        int col = letters_to_i(letters);

        int num = 0;
        while(i < size(s)) num = num * 10 + (s[i++] - '0');

        cout << "R" + to_string(num) + "C" + to_string(col) << '\n';
    }

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int tt; cin >> tt;
    while(tt--) {
        solve();
    }



    return 0;
}