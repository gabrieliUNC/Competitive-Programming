#include <bits/stdc++.h>
#include <iostream>
#include <array>
#include <vector>
#include <iostream>

using namespace std;

main(){
    int t;
    cin >> t;
    cin.ignore();
    for(int l; l<t; l++){
    string s {""};
    getline(cin, s);
    int count {0};
    bool lesgo = true;
    while (lesgo){
    bool rip = true;
    for(int i=0; i<s.length(); i++){
        if((s[i]=='1')&&(s[i+1]=='0')){
            rip = false;
            count+=1;
            s.erase(i, 1);
            s.erase((i), 1);
        }
        else if((s[i]=='0')&&(s[i+1]=='1')){
            rip = false;
            count+=1;
            s.erase(i, 1);
            s.erase((i), 1);
        }
    }
    if((s.length()<1)||(rip)){
            lesgo = false;
        }
    }
    if (count%2==1){
        cout << "DA"<<endl;
    }
    else{
        cout << "NET"<<endl;
    }
    }
    
    
    return 0;
}
