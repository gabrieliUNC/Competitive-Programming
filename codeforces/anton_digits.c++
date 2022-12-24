#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(){
    int array[4];
    int count=0;
    for(int i=0; i<4; i++){
        cin >> array[i];
    }
    bool lesgo = true;
    bool lesgo2 = false;

    while(lesgo){
    if(array[0]>=1&&array[2]>=1&&array[3]>=1){
        count +=256;
        array[0]-=1;
        array[2]-=1;
        array[3]-=1;
    }
    else{
        lesgo2 = true;
    }
    if(array[0]>=1&&array[1]>=1&&lesgo2){
        count +=32;
        array[0]-=1;
        array[1]-=1;
    }
    if((array[0]<1)||(array[0]<1||array[1]<1) && (array[2]<1||array[3]<1)){
        lesgo = false;
    }
    }
    
    return count;


}

main(){
    cout << solve();
    return 0;
}