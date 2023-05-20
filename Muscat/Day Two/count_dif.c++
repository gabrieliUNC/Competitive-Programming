#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, m; cin >> n >> m;

    vector<ll> a(m);
    for(int i = 0; i < m; ++i){
		string temp; cin >> temp;

        ll x = 0;
        int pow = 0;

		for(int i = temp.size() - 1; i >= 0; --i){
            if(temp[i] == '1') x += (1 << pow);
            ++pow;
        }

		a.push_back(x);
	}

    vector<ll> basis;
	basis.clear();

    for (ll x: a) {
        ll temp = x;
        for (ll b: basis) temp = min(temp, (temp^b));
        if (temp) basis.push_back(temp);
    }

	cout << (pow(2, basis.size())) << '\n';
    

    return 0;   
}
