#include <bits/stdc++.h>
#include <array>
#define ll long long
using namespace std;

main(){
ll t;
cin >> t;
while (t--){
    ll n; cin >> n;
    cin.ignore();
    string s {""};
    getline(cin, s);
    const ll int length = s.length();
    ll int count = 0;
    for (int i=0; i<length; i++){    
        if (s[i]=='1'){
            count +=1;
        }
    }
    if((s[0]=='1')||(s[n-1]=='1')){
        cout << length*2<<endl;
    }
    else if(count==0){
        cout << length<<endl;
    }
    else{
        ll int staircase = INT_MAX;
        ll int staircase2 = -1;
        for(int x=length-1; x>=0; x--){
            if(s[x]=='1'){
                if(staircase>x){
                    staircase = x;
                }
            }
        }
        for(int y=0; y<length; y++){
            if(s[y]=='1'){
                if(staircase2<y){
                    staircase2=y;
                }
            }
        }
        int answer2 = (staircase2+1)*2;
        int answer = (length-staircase) * 2;
        if(answer>answer2){
        cout << answer << endl;
        }
        else{
            cout << answer2<<endl;
        }
    }
    
}
return 0;
}