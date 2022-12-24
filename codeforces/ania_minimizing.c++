#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    ll n, k; cin >> n >> k;
    string s;
    cin.ignore();
    getline(cin, s);
    if(k==0){
        cout << s<<endl;
    }
    else{
    if(n==1){
        s = '0';
    }
    else{
        if((s[0]!='1')&&(k>=1)){
            s[0]='1';
            k--;
        }
        ll int i=1;
        while((i<=k)&&(i<n)){
            if(s[i]!='0'){
                s[i]='0';
                i++;
            }
            else if(s[i]=='0'){
                i++;
                k++;
            }
            else{
                break;
            }
        }
    }
    
    std::cout << s<<endl;

    }
    return 0;
}