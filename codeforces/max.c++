#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    string an; int a[n], comp[10];
    cin >> an;
    int i=0;
    for(char ch: an){
        a[i] = (ch - '0');
        i++;
    }
    for(int i=1; i<10; ++i){
        cin >> comp[i];
    }
    
    for(int i=0; i<n; i++){
        if(comp[a[i]]>a[i]){
    while(i<n && comp[a[i]]>=a[i]){
        a[i]=comp[a[i]];
        i++;
    }
    break;
    }
}
    for(int e: a){
        cout << e;
    }
    cout << "\n";
}