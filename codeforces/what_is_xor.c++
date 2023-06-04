#include <bits/stdc++.h>
using namespace std;


const int XOR = INT32_MAX;

int main(){


    while(1){
        cout << '\n';
        int x, y; cin >> x >> y;
        cout << (x ^ XOR) << ' ' << (y ^ XOR) << '\n';
    }

    return 0;
}