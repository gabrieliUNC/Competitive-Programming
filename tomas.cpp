#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll solve() {
    ll N; cin >> N;
    vector<int> divisors;

    for(int i = 1; i <= 10; ++i) {
        if(!(N % i)) divisors.push_back(i);
    }

    for(auto div : divisors) cout << div << ' ';
    cout << '\n';

    return N;
}


int main() {
    int tt; cin >> tt;

    while(tt--) cout << solve() << '\n';



    return 0;
}