#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b, i; cin >> n >> a >> b;
    for(i=100;;--i)if((a>=i) && (b>=i) && ((a/i)+(b/i)>=n))break;
    cout << i;


    return 0;
}