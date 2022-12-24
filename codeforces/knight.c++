#include <bits/stdc++.h>
using namespace std;

main(){
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
int ans = 46;
string s1; cin >> s1;
string s2; cin >> s2;
bool ok = true;
bool okay = true;
if(s2[0] < 'b' || s2[0] > 'f') {
    ok = false;
}
if(s2[1] < '4' || s2[1] > '6'){
    okay = false;
}

if(!ok && !okay){
    ans-=4;
}
else if(!ok || !okay){
    ans-=4;
}
else{
    ans-=8;
}

cout << s2[0]-s1[0] << "\n";

if((s2[0]-s1[0] == 1 || s2[0]-s1[0] == -1)){
    ans++;
}
if(s2[1]-s1[1] == 1 || s2[1]-s1[1] == -1){
    ans++;
}

cout << ans << "\n";


return 0;
}