#include <bits/stdc++.h>
#define ll long long
#define ld double

using namespace std;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool one[4], two[4], three[4], four[4];
    for(int i=0; i<4; ++i)
        cin >> one[i];
    for(int i=0; i<4; ++i)
        cin >> two[i];
    for(int i=0; i<4; ++i)
        cin >> three[i];
    for(int i=0; i<4; ++i)
        cin >> four[i];
    bool first = false, second = false, third = false, fourth = false;
    for(int i=0; i<3; ++i){
        if (one[i] && one[3]){
            first = true;
        }
    }
    for(int i=0; i<3; ++i){
        if (two[i] && two[3]){
            second = true;
        }
    }
    for(int i=0; i<3; ++i){
        if (three[i] && three[3]){
            third = true;
        }
    }
    for(int i=0; i<3; ++i){
        if (four[i] && four[3]){
            fourth = true;
        }
    }
    if(first || second || third || fourth){
        cout << "YES";
        return 0;
    }
    else{
        if(one[3]&&(three[1] || two[0] || four[2])){
            cout << "YES";
            return 0;
        }
        if(two[3]&&(four[1] || three[0] || one[2])){
            cout << "YES";
            return 0;
        }
        if(three[3]&&(one[1] || four[0] || two[2])){
            cout << "YES";
            return 0;
        }
        if(four[3]&&(two[1] || one[0] || three[2])){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";

    return 0;
}