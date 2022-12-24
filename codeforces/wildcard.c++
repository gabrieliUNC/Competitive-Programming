#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    if(s==t){
        cout << "YES" << "\n";
    }
    else if(n>m+1){
        cout << "NO" << "\n";
    }
    else{
    int i=0; bool ok = false;
    while(i<n){
        if(s[i]=='*'){
            ok = true;
            break;
        }
        i++;
    }
    if(!ok){
        cout << "NO " << "\n";
        return 0;
    }
    else{
        int i=n-1;
        int j=m-1;
        while(i>=0){
            if(s[i]=='*') {
                break;
            }
            else if(s[i]!=t[j]){
            cout << "NO" << "\n";
            return 0;
            }
            j--;
            i--;
        }
        i = 0;
        j = 0;
        while(i<s.length()){
            if(s[i]=='*') { break; }
            else if (s[i]!=t[j]){
                cout << "NO" << "\n";
                return 0;
            }
            i++;
            j++;
        }
    }
    cout << "YES" << "\n";
    }
return 0;
}