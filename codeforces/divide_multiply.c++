#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    ll n; cin >> n;
    ll tt = n-1;
    ll ans[n] = {0};
    vector <ll> o;
    vector <ll> e;

    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        if(temp%3==0){
            o.push_back(temp);
        }
        else{
            e.push_back(temp);
        }
    }

    sort(o.begin(), o.end(), greater <int>());
    sort(e.begin(), e.end(), greater <int>());


    ans[0] = o[0];
    int it=0;

    bool run = true;
while(run){
    for(int i=0; i<n; ++i){
        cout << "ans[i]: "<< ans[i] << endl;
        cout << "o[i]: "<< o[i+1] << endl;
        cout << "e[i]: "<< e[i] << endl;
        if(ans[i]/3 == o[i+1]){
            ans[i+1] = o[i+1];
        }
        else if(ans[i]*2 == e[i]){
            ans[i+1] = e[i];
        }
        else{
            ans[0] = o[++it];
            break;
        }
        if(ans[n-1]!=0){
            run = false;
        }
    }
    }
    for(int i=0; i<n; ++i){
        cout << ans[i] << endl;
    }
}