#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

main (){
string morse_code;
char sol {'-'};
cin>>morse_code;

for(int i=0; i<morse_code.length(); i++){
    if(morse_code[i]==sol){
        if(morse_code[i+1]==sol){
            cout << 2;
            i += 1;
        }
        else{
            cout << 1;
            i +=1;
        }
    }
    else {
        cout << 0;
    }
}

}
