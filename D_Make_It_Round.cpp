#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll gcd(long long int a, long long int b) 
{ 
  if (b == 0LL) 
    return a; 
  return gcd(b, a % b); 
} 
  
// Function to return LCM of two numbers  
__int128 lcm(ll a, ll b) 
{ 
    __int128 ia = (__int128) a;
    __int128 ib = (__int128) b;
    return (ia / (__int128) gcd(a, b)) * ib; 
}



__int128 solve() {
    ll num, k; cin >> num >> k;
    ll r = num * k;
    __int128 ans = 1;

    for(ll i = 1; i <= 18; ++i) {
        __int128 l = lcm(num, (ll)pow(10LL, i));
        if(l > r) break;
        ans = l;
    }

    ans = floor((ll)((__int128) r / ans)) * ans;
    
    
    return ans;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}


int main() {

    int tt; cin >> tt;
    while(tt--) {
        print(solve());
        cout << '\n';
    }



}