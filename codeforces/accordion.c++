#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s; cin >> s;

    int i = 0, cnt = 0, j = s.size();
    bool ok = 0;

    while(i < j) {
        if(s[i] == '['){
            ok = 1;
            break;
        }
        i++;
    }
    
    if(!ok){
        cout << -1 << '\n';
        return 0;
    } else{
        bool found = 0;

        j--;

        while(j > i){
            if(s[j] == ']'){
                found = 1;
                break;
            }
            j--;
        }

        if(!found){
            cout << -1 << '\n';
            return 0;
        }

        while(i < j){
            if(s[i] == ':'){
                cnt++;
                break;
            }
            i++;
        }

            while(j > i){
                if(s[j] == ':'){
                cnt++;
                break;
            }
                j--;
            }
        
        if(cnt != 2){
            cout << -1 << '\n';
            return 0;
        }

        while(i < j){
            if(s[i] == '|') cnt++;
            i++;
        }

        cout << cnt + 2 << '\n';

    }



    return 0;
}