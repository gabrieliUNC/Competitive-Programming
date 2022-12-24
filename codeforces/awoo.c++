#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s, t; cin >> s >> t;
        if(n==1){
            if(s==t)cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else{
            if(s==t){cout << "YES" << '\n'; continue;}
            else{
            int first[n], second[n];
            for(int i=0; i<n; ++i){
                if(s[i]=='a')first[i]=0;
                if(s[i]=='b')first[i]=1;
                if(s[i]=='c')first[i]=2;
            }
            for(int i=0; i<n; ++i){
                if(t[i]=='a')second[i]=0;
                if(t[i]=='b')second[i]=1;
                if(t[i]=='c')second[i]=2;
            }

            bool okay = true;
            for(int i=0; i<n; ++i){
                if(first[i]==second[i])continue;
                bool ok = true;
                int j = i;
                while(j<n){
                    if(second[i]<first[j]){ok=false; break;}
                    if(second[i]==first[j]) break;
                    j++;
                }
                if(ok){
                    while(j>=i){
                        swap(first[j], first[j-1]);
                        j--;
                    }
                }
                else{
                    okay = false;
                    break;
                }
            }
            if(okay)cout << "YES" << '\n';
            else cout << "NO" << '\n';
            
        }



    }

    }
    return 0;

}