#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    ll n, k, m, num, max=0, sub_max=0, max_i=0, sub_max_i=0, count=0; cin >> n >> k >> m >> max;
    n--;
    while(k>0){
        if(k>=m){
        max_i+=m; k-=m; }
        else {
            max_i+=k;
            k=0;
        }
        if(k>0){
            sub_max_i++;
            k--;
            }
        }

    
    while(n--){
        cin>>num;
        if(num>max){
            sub_max=max;
            max=num;
        }
        else if(num>sub_max){
            sub_max=num;
        }
    }
    count += (max*max_i);
    count += (sub_max*sub_max_i);
    cout << count;

    return 0;
}