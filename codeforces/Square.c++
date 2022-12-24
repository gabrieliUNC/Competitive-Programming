#include <iostream>
using namespace std;

main(){
int i=0;
int a, b, c, d, e;
cin >> a;

while (i<a) {
    cin >> b >> c >> d >> e;

    if(b>c)swap(b, c);
    if(d>e)swap(d, e);

    if(b+d==c && b+d==e){
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }

    i+=1;

}
    return 0;
}