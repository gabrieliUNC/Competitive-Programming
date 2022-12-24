#include <iostream>
#include <array>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solve(){
int n;
int k;
cin >> n >> k;
vector<int> a(n);
long long int min = INT_MAX;
int max = 0;

for(int i: a){
    cin >> a[i];
    if(min>a[i]){
        min = a[i];
    }
    if(max<a[i]){
        max = a[i];
    }
}

int comp = min + k;
for(int l: a){
    if((max-min)>(2*k)){
        return -1;
    }
}
return comp;
}

main(){
int t;
cin >> t;
while (t--){
    int answer = solve();
    cout << answer<<endl;
}


return 0;
}