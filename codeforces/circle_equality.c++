#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if(n % 2 == 0){
        cout << "NO" << '\n';
    } 
    else {
        cout << "YES" << '\n';
        cout << 1 << ' ';
        for(int i = 4; i < (n * 4); i += 4){
            cout << i % (2 * n) << ' ' << (i + 1) % (2 * n) << ' ';
        }

        cout << 2 * n << '\n';
    }


    return 0;
}