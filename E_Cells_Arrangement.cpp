#include <bits/stdc++.h>
#include <time.h>
#define F first
#define S second
using namespace std;

int n;


void solve() {
    cin >> n;
    
    cout << 1 << ' ' << 1 << '\n';
    cout << 1 << ' ' << 2 << '\n';

    for(int i = 3; i <= n; ++i) {
        cout << i << ' ' << i << '\n';
    }

    cout << '\n';
}

int main() { 

    int tt; cin >> tt;
    while(tt--) solve();




    return 0;
}