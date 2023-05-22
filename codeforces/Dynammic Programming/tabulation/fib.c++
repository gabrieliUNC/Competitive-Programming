#include <bits/stdc++.h>
#define ll long long
using namespace std;


const ll N = 1e8 + 8;
ll fib[N];

int main(){
memset(fib, 0, N);

fib[0] = 0;
fib[1] = 1;

for(int i = 2; i < N; ++i) fib[i] = fib[i - 1] + fib[i - 2];

ll n; cin >> n;

cout << fib[n];

return 0;
}