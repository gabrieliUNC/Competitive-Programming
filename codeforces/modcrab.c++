#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h, a, p, m_h, m_a; cin >> h >> a >> p >> m_h >> m_a;
    vector<string> moves;
    moves.clear();

    while( m_h > 0){
        if(h - m_a > 0 || m_h - a <= 0) moves.push_back("STRIKE"), h -= m_a, m_h -= a;
        else moves.push_back("HEAL"), h += p, h -= m_a;
    }

    cout << moves.size() << '\n';
    for (string e: moves) cout << e << '\n';



    return 0;
}