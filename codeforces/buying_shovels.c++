#include <iostream>
using namespace std;

int solve(){
    int k; int r;
    cin >> k >> r;
    for(int i=1; i<1000; i++){
        if((i*k)%10==0){
            return i;
        }
        else if ((i*k)%10==r){
            return i;
        }
    }
    return 0;
}



int main(){
    cout << solve()<<endl;
    return 0;

}
