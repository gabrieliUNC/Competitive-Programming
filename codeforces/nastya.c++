#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    ll n=0, k=0, count=0, min1=0, min2=0; cin >> n >> k;
    min1 = n-k;
    min2 = k-1;
    if(min2>min1){swap(min2, min1);}
    count+=min2;
    count+=(3*n);
    cout << count<< endl;



    return 0;
}