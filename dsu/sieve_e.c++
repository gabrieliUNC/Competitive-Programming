#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e9 + 7;

bool p[inf];

void sieve(int x){
    //Calculates all primes up to x
    p[0] = 1;
    for (int i = 3; i*i <= x; i += 2) {
        if (p[i / 2] == 0) {
            for (int j = 3 * i; j <= x; j += 2 * i)
                p[j / 2] = 1;
        }
    }
}

void divisor_sieve(int n){
    int divisors[n + 1];
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; j += i)
                ++divisors[j];
}

void sum_divisor_sieve(int n){
    int sumdiv[n + 1];
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; j += i)
                sumdiv[j] += i;
}

void eueler_totient(int n){
    //Finds the numbers relative prime to n
    int totient[n + 1];
        for (int i = 1; i <= n; ++i) totient[i] = i;

        for (int i = 2; i <= n; ++i)
            if (totient[i] == i)
                for (int j = i; j <= n; j += i)
                    totient[j] -= totient[j] / i;
}

void big_sieve(int n){
    //used to find the factors of a large number
    int big[n + 1] = {1, 1};
    for (int i = 1; i <= n; ++i)
    if (big[i] == 1)
    for (int j = i; j <= n; j += i)
    big[j] = i;

    vector<int> factors;
    while (n > 1) { factors.push_back(big[n]); n /= big[n]; }
}