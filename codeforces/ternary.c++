#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int solve(ll input, ll comp){
    ll count = 0;
    ll j=ceil((cbrt(input))), k=ceil((cbrt(comp)));
    ll j_it = j, k_it = k; 
    vector<ll int> a(j, 0);
    vector<ll int> b(k, 0);
    cout << "j_it: " << j_it<<endl;
    cout << "k_it: " << k_it << endl;


    while(input>0){
        if(input>=(pow(3, j))*2){
            input-=((pow(3, j))*2);
            a[j]=2;
            j--;
        }
        else if(input>=(pow(3, j))){
            input-=(pow(3, j));
            a[j]=1;
            j--;
        }
        else if ((a[j]!=2)&&(a[j]!=1)){
            a[j]=0;
            j--;
        }
    }
    while(comp>0){
        if(comp>=(pow(3, k))*2){
            comp-=((pow(3, k))*2);
            b[k]=2;
            k--;
        }
        else if(comp>=(pow(3, k))){
            comp-=(pow(3, k));
            b[k]=1;
            k--;
        }
        else if((b[k]!=2)&&(b[k]!=1)){
            b[k]=0;
            k--;
        }
    }
    

    // while(j<k){
    //     a.push_back(0);
    //     j++;
    // }
    // while(k<j){
    //     b.push_back(0);
    //     k++;
    // }

    
    for(int z=j_it; z>=0; z--){
        ll temp = abs(b[z]+a[z]);
        count+= ((temp%3)*(pow(3, z)));
    }

    for(int x=0; x<4; x++){
        cout << "a[x]" << a[x]<<endl;
    }
    for(int y=0; y<4; y++){
        cout << "b[y]: " << b[y] << endl;
    }

    return count;

}

main(){
    ll input, comp; cin >> input >> comp;
    ll a = solve(input, comp);
    cout << "answer: " << solve(input, a) << endl;
    return 0;
}