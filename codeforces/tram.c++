#include <iostream>
#include <array>
#include <vector>
using namespace std;

main(){
    int t;
    cin >> t;
    int temp=0;
    int result=0;
    while ((t)--){
        int a;
        int b;
        cin >> a;
        cin >> b;
        temp += (b-a);
        result = max(result, temp);
    }
    cout << result;
}