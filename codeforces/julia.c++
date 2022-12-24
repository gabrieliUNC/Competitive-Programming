#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, ans=0; cin >> n;
    while(n!=0){
        if(n<=9){
            n=0;
            ans++;
        }
        else{
            ll r = n;
            ll largest = 0;
            while(r!=0){
                ll x = r%10;
                largest = max(x, largest);
                r/=10;
            }
            n-=largest;
            ans++;
        }
    }
    cout << ans;

    return 0;
}