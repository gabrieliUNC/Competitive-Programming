#include <iostream>
using namespace std;

main(){
    int n; int h;
    cin >> n >> h;
    int count;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a>h){
            count++;
        }
    }
    cout << n + count;
    return 0;
}