#include <bits/stdc++.h>
using namespace std;

const unsigned long long int N = 1e8 + 6;

unsigned long long int f[N];

unsigned long long int fib(unsigned long long int n){
    return f[n];
}

unsigned long long int slow_fib(unsigned long long int n){
    if(n <= 2) return 1;
    return slow_fib(n - 1) + slow_fib(n - 2);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    memset(f, 0, N);

    f[0] = 1;
    f[1] = 1;

    for(long long int i = 2; i < N; ++i) f[i] = f[i - 1] + f[i - 2];

    int go; cin >> go;

    unsigned long long int n; cin >> n;
    --n;

    if(go) cout << "fast: " << fib(n) << '\n';
    else cout << "slow: " << slow_fib(n) << '\n';

    return 0;
}