#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; cin >> n; string s; cin >> s;
    map<string, int> m;
    int ans = 0;
    if(n==1){
        if(s=="A"){ cout << 1; }
        if(s=="B") { cout << 2; }
        if(s=="C") { cout << 0; }
    }
    else{
    for(int i=1; i<=n; ++i){
        if(s[i-1]=='A' && s[i]=='B'){
            m["AB"]++;
            ++i;
        }
        else if(s[i-1]=='A'){
            m["A"]++;
        }
        else if(s[i-1]=='B'){
            m["B"]++;
        }
        else if (s[i-1]=='C'){
            m["C"]++;
        }
    }
    ans -= (m["C"]*(m["AB"]*m["AB"]));
    ans += (m["AB"]*4);
    ans += (m["A"]*1);
    ans += (m["B"]*2);
    cout << ans << "\n";
    }
    return 0;
}
