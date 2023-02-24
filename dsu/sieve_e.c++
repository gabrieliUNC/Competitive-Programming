#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e9 + 7;

bool p[inf];

void sieve(int x){
    p[0] = 1;
    for (int i = 3; i*i <= x; i += 2) {
        if (p[i / 2] == 0) {
            for (int j = 3 * i; j <= x; j += 2 * i)
                p[j / 2] = 1;
        }
    }
}

int main(){
    memset(p, 0, inf);
    int n; cin >> n;
    sieve(n);
    cout << 2 << '\n';
    for(int i = 3; i <= n; ++i) if(i % 2 == 1 && p[i / 2] == 0) cout << i << '\n';

}