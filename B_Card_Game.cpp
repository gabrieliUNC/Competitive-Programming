#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;

int eval(const int& alice, const int& bob) {
    if(alice > bob)
        return 1;
    if(alice < bob)
        return -1;
    return 0;
}

void solve() {
    int ans = 0;
    vector<int> cards(4);
    for(auto& e : cards)
        cin >> e;

    auto play = [&ans](const int& card1, const int& card2, const int& card3, const int& card4) {
        int score{0};
        score += eval(card1, card3);
        score += eval(card2, card4);
        if(score > 0)
            ans++;
    };

    // suneet plays 1
    play(cards[0], cards[1], cards[2], cards[3]);
    play(cards[0], cards[1], cards[3], cards[2]);

    // suneet plays 2
    play(cards[1], cards[0], cards[2], cards[3]);
    play(cards[1], cards[0], cards[3], cards[2]);

    
    cout << ans << '\n';
}


int main() {
    int tt; cin >> tt;
    while(tt--)
        solve();




    return 0;
}