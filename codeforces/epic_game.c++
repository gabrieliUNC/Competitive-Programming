#include <iostream>
#include <array>
#include <vector>
using namespace std;

int gcd(int player, int stones){
        for(int i=player; i>0; i--){
            if(player%i==0 && stones%i==0){
                return i;
            }
        }
        }
        
    


main(){
int a; int b; int n;
cin >> a >> b >> n;
int count = 1;

    while (n>0){
        if (count%2==1&&(gcd(a,n)<=n)){
            n-= gcd(a, n);
            count ++;
        }
        else if (gcd(b,n)<=n){
            n-= gcd(b, n);
            count ++;
        }
        else{
            break;
        }
    }
    if(count%2==1){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}