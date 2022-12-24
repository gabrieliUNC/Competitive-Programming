#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N = 1000 * 0xffLL;
    int a, b, c, d; cin >> a >> b >> c >> d;
    set <int> first;
    set <int> second;
    if((a%2==0 && b%2!=0 && c%2==0 && d%2==0) || (a%2==0 && b%2==0 && c%2==0 && d%2!=0)){
        cout << -1;
    }
    else{
        int i = 0;
        while(i<N){
            first.insert(b + (a*i));
            second.insert(d + (c*i));
            ++i;
        }
        int j = 0;
        for(auto& e: first){
            if(j>1000){
                cout << -1;
                break;
            }
            if(second.find(e)!=second.end()){
                cout << e;
                break;
            }
            j++;
        }
    }

    return 0;
}