#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    int curr = 1;
    int neg = 0, pos = 1;

    for(int i = 0; i < n; ++i){
        ll temp; cin >> temp;
        if(temp < 0)curr = -curr;
        if(curr > 0)++pos;
        else ++neg;
    }

    cout << 1LL * neg * pos << ' ' << (1LL * n * (n+1)) / 2 - pos * neg << '\n';

    return 0;
}