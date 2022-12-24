#include <bits/stdc++.h>
using namespace std;


bool is_prime(int in){
    for(int i=2; i<in; ++i){
        if(in%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int n, k; cin >> n >> k;
    vector <int> primes(2262);
    primes.clear();
    vector <int> ans(2262);
    ans.clear();
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i=3; i<20000; ++i){
        if(is_prime(i)){
            primes.push_back(i);
        }
    }
    for(int i=1; i<2262; ++i){
        int temp = primes[i]+primes[i-1] + 1;
        if(is_prime(temp)){
            ans.push_back(temp);
        }
    }

    int e = lower_bound(ans.begin(), ans.end(), n) - ans.begin() + 1;
    if(e<k)cout << "NO" << '\n';
    else cout << "YES" << '\n';

    return 0;

}