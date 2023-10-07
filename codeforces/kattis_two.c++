#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, a, b; cin >> n >> a >> b;
    bool found_max = 0, found_min = 0;
    vector<int> mem(n);

    for(int i = 0; i < n - 1; ++i) cin >> mem[i];

    for(int i = 0; i < n; ++i){
        if(mem[i] == a) found_min = 1;
        if(mem[i] == b) found_max = 1;
    }

    if(a == b && !found_min && !found_max) cout << a << '\n';
    else if(!found_min && !found_max) cout << -1 << '\n';
    else if(!found_min) cout << a << '\n';
    else if(!found_max) cout << b << '\n';
    else{
        for(int i = a; i <= b; ++i) cout << i << '\n';
    }
    



    return 0;
}