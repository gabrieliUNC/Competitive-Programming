#define ll long long
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

vector<int> factorize(int k) {
	vector<int> ans;
	while(k > 1) {
		ans.push_back(sp[k]);
		k /= sp[k];
	}
	return ans;
}