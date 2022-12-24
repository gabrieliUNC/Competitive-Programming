#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

main(){
    ll t; cin >> t; string s;
    cin.ignore();
    while (t--){
    getline(cin, s);
    ll int a=0; ll int b=s.length()-1;
    bool found_palindrome = false;
    ll int count = 0;
    while (found_palindrome==false){
        if(s[a]==s[b]){
            count +=1;
        }
        if(b==0){
            found_palindrome = true;
        }
        a++;
        b--;
    }
    if(count!=s.length()){
        cout << s<<endl;
    }
    else{
        char arr[s.length()];
        for(int x=0; x<s.length(); x++){
            arr[x] = s[x];
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        sort(arr, arr + n);
        for(int y=0; y<s.length(); y++){
            s[y] = arr[y];
        }
        if(s[0]!=s[s.length()-1]){
        cout << s<<endl;
        }
        else{
            cout << -1<<endl;
        }
    }
    }

    return 0;
}