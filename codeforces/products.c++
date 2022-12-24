#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n; cin >> n;
    vector<bool> in(n);
    vector<ll> prefix(n);
    for(int i=0; i<n; ++i){
        ll temp; cin >> temp;
        in[i] = temp>0 ? true : false;
        if(i==0) prefix[i] = temp<0 ? 1 : 0;
        else{
            prefix[i] = prefix[i-1];
            prefix[i] += temp<0 ? 1 : 0;
        }


        }
    ll pos=0, neg=0;
    for(int i=0; i<n; ++i){
        for(int len=2; i+len-1<n; ++len){
            auto copy = prefix[i+len-1];
            copy -= prefix[i-1];
            if((copy%2==0&&(len-copy)%2!=0) || (copy%2!=0&&(len-copy)%2==0)) neg++;
            else pos++;
        }
    }

    
    cout << neg << "\n";
    cout << pos << "\n";



    return 0;
}