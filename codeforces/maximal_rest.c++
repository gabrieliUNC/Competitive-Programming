#include <iostream>
#include <array>
using namespace std;

main(){
    int t;
    cin >> t;
    int temp1;
    int a;
    int b;
    int array[t-1];

    for(int k; k<t; k++){
        int temp;
        cin >> temp;
        array[k] = temp;
        cout << "number: " << array[k] << endl;
    }


    if(array[0]==1 && array[t-1]==1)
            {
                b=2;

        for(int j=1; j<t; j++){
                if(array[j]==1){
                    b++;
                }
                else{
                
                    break;
                }
        
    }
            }

    for(int i=0; i<t; i++){
        
        if(array[i]==1){
            a++;
        }
        else{
        if(temp1<a){
            temp1 = a;
        }
        a = 0;
        }
    }

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "temp1: " << temp1 << endl;
    
    if (temp1>a){
        a = temp1;
    }

    if(a>b){
        cout << a;
    }
    else{
        cout << b;
    }

    }