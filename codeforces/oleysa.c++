#include <bits/stdc++.h>
#define ll long long
using namespace std;


main(){
ll n; int t; cin >> n >> t;
string part = to_string(t);
string s ("");


if(n==1 && t==10){
    cout << -1;
    return 0;
}

if(t==10){
    for(int i=0; i<n-1; ++i){
        s.append("1");
    }
    s.append("0");
}

else{

for(int i=0; i<n; ++i){
    s.append(part);
}
}

cout << s << "\n";


return 0;
}