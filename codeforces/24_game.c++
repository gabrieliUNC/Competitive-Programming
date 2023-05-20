#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n;

    if(n <= 3){
        cout << "NO" << '\n';
        return 0;
    }
    cout << "YES" << '\n';

    if(n == 4){
        cout << "4 * 3 = 12\n";
        cout << "12 * 2 = 24\n";
        cout << "24 * 1 = 24\n";
    }

    if(n == 5){
        cout << "5 * 4 = 20\n";
        cout << "20 + 3 = 23\n";
        cout << "23 + 2 = 25\n";
        cout << "25 - 1 = 24\n";
    }

    if(n > 5){
        cout << "6 * 4 = 24\n";
        vector<int> rem;
        for(int i = 1; i <= n; ++i){
            if(i != 6 && i != 4) rem.push_back(i);
        }
        
        ll curr = 24;

        int i = 0;
        while(rem.size() > 1){
            if(i){
                cout << curr << " - " << *--rem.end() << " = " << curr - *--rem.end() << '\n';
                curr -= *--rem.end();
                rem.erase(--rem.end());

                if(*--rem.end() == 1 && curr == 24){
                    cout << curr << " * 1 = 24\n";
                    rem.erase(--rem.end());
                    break; 
                }

                cout << curr << " + " << *--rem.end() << " = " << curr + *--rem.end() << '\n';
                curr += *--rem.end();
                rem.erase(--rem.end());
            }
            else{
                cout << curr << " + " << *--rem.end() << " = " << curr + *--rem.end() << '\n';
                curr += *--rem.end();
                rem.erase(--rem.end());

                if(*--rem.end() == 1 && curr == 24){
                    cout << curr << " * 1 = 24\n";
                    rem.erase(--rem.end());
                    break; 
                }  

                cout << curr << " - " << *--rem.end() << " = " << curr - *--rem.end() << '\n';
                curr -= *--rem.end();
                rem.erase(--rem.end());
            }
            i ^= 1;
        }

        if(rem.size()){
            if(curr == 25) cout << curr << " - 1  = 24\n";
            if(curr == 24) cout << curr << " * 1 = 24\n";
            if(curr == 23) cout << curr << " + 1 = 24\n";
        }

    }






    return 0;
}