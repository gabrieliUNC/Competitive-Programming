#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int BASIS_DIM = 20;
int basis_size = 0;
int basis[BASIS_DIM];


void insertVector(int mask) {
	for (int i = 0; i < BASIS_DIM; i++) {
		if ((mask & 1 << i) == 0) continue;

		if (!basis[i]) {
			basis[i] = mask;
			++basis_size;
			
			return;
		}

		mask ^= basis[i];
	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int a;
		cin >> a;

		insertVector(a);
	}

	cout << (1 << basis_size) << endl;

	return 0;
}