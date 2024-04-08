#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;


const int mxN = 1e7 + 8;
bool primes[mxN];
int len, sp[mxN];

void Sieve(){
	for (int i = 2; i < mxN; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (ll i = 3; i < mxN; i += 2){
		if (!primes[i]){
			sp[i] = i;
			for (ll j = i; (j*i) < mxN; j += 2){
				if (!primes[j*i])	primes[j*i] = true, sp[j*i] = i;
			}
		}
	}
}

vector <int> factorize(int k) {
	vector <int> ans;
	while(k > 1) {
		ans.push_back(sp[k]);
		k /= sp[k];
	}
	return ans;
}

int solve() {
    ll a, b; cin >> a >> b;
    if(gcd(a, b) != 1) return 0;

    int dif = b - a;
    if(sp[dif] == 0) return -1;

    auto factors = factorize(dif);

    int minn = INT_MAX;

    for(auto& factor : factors) {
        minn = min(minn, (int) ((factor * ceil((double) a / (double) factor)) - a));
    }

    return minn;
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Sieve();
    int n; cin >> n;

    while(n--) {
        cout << solve() << '\n';
    }
    
    


    /*
    
    Find divisors of distance between a, b 

    this gives next divisor <--



    */


    return 0;
}