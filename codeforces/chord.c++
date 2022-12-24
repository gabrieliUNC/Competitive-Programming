#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector <string> dp = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
    int in[3];
    for(int i=0; i<3; ++i){
        string temp; cin >> temp;
        for(int i=0; i<12; ++i){
            if(dp[i]==temp){
                in[i] = i;
                cout << in[i];
                break;
                }
        }
    }
    sort(in, in+3);
    for(int i=0; i<3; ++i) cout << dp[i];
    if(in[1]-in[0]==3 && in[2]-in[1]==4) {cout << "minor"; return 0;}
    sort(in, in+3, greater<int>());
    for(int i=0; i<3; ++i) cout << dp[i];
    if(in[1]-in[0]==4 && in[2]-in[1]==3) {cout << "major"; return 0;}


    return 0;
}