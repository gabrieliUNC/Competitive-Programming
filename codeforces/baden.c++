#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int mod = n % 36;
    int ft = n / 36;
    int in = mod / 3;
    int left = mod % 3;
    if(left > 1)in++;
    if(in==12){
        ft++;
        in=0;
    }

    cout << ft << '\n';
    cout << in << '\n';


    return 0;
}