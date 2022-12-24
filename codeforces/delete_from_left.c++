#include <bits/stdc++.h>
using namespace std;

main(){
    string a, b; cin >> a >> b;
    if(a==b) { cout << 0; return 0; }
    int i = a.length()-1;
    int j = b.length()-1;
    while(a[i]==b[j]){
        --j;
        --i;
    }  
    int ans = (i+1) + (j+1);
    cout << ans << "\n";

    return 0;
}