#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map <int, int> m;
    for(int i=0; i<n; ++i){
        int temp; cin >> temp;
        m[temp]++;
    }
    if(m[1]==0){
        while(m[2]>0){
            cout << 2 << "\n";
            m[2]--;
        }
    }
    else if(m[2]==0){
        while( m[1]>0){
            cout << 1 << "\n";
            m[1]--;
        }
    }

    else{
        cout << 2 << "\n";
        cout << 1 << "\n";
        m[2]--;
        m[1]--;
        while(m[2]>0){
            cout << 2 << "\n";
            m[2]--;
        }
        while(m[1]>0){
            cout << 1 << "\n";
            m[1]--;
        }
    }


    

    return 0;
}
