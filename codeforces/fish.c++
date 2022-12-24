#include <bits/stdc++.h>
using namespace std;

main(){
    int ans; cin >> ans;
    int n; cin >> n;
    for(int i=0; i<n; ++i){
        char temp; cin >> temp; int pop; cin >> pop;
        if(temp == 'G'){
            ans+=pop;
        }
        else{
            ans-= (ans%pop);
        }
    }

    cout << ans << "\n";



    return 0;
}