#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, pos; ll curr; cin >> n >> pos;
    vector<ll> points; vector<ll> add(n-1);
    for(int i = 0; i < n; ++i){
        ll temp; cin >> temp;
        if(i+1==pos)curr = temp;
        else points.push_back(temp);
    }
    ll temp; cin >> temp; curr += temp;
    for(int i = 0; i < n-1; ++i)cin>>add[i];
    sort(points.begin(), points.end());
    sort(add.begin(), add.end(), greater<int>());

    for(int i = 0; i < n - 1; ++i)points[i]+=add[i];
    
    sort(points.begin(), points.end());
    int i;
    for(i = 0; i < n - 1; ++i){
        if(curr < points[i])break;
    }
    cout << n - i << '\n';


    return 0;
}