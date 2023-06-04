#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

const int mod = INT_FAST32_MAX;
int e = 0, o = 0, n;
vector<int> a;

void find_xor(){
    for(int i = 0; i < n - 1; ++i){
        if(i % 2){
            o ^= a[i];
        } else{
            e ^= a[i];
        }
    }
}


void solve(){
    cin >> n;
    a.resize(n);

    // create first sum
    for(int i = 0; i < n - 2; ++i) a[i] = i + 1;

    //fill last elements with xor sum
    a[n - 2] = mod;

    o = 0; e = 0;
    find_xor();

    // cout << o << '\n';
    // cout << e << '\n';

    int curr = o ^ e;

    a[n - 2] = curr;
    a[n - 1] = mod;

    if(curr == mod){
        for(int i = 0; i < n - 2; ++i) a[i] = i;

        //fill last elements with xor sum
        a[n - 2] = mod;

        o = 0; e = 0;
        find_xor();

        // cout << o << '\n';
        // cout << e << '\n';

        int curr = o ^ e;

        a[n - 2] = curr;
        a[n - 1] = mod;

    }


  

    //print array
    int turn = 0;
    for(int i = 0; i < n; ++i) {
        if(turn) cout << a[i] << ' ';
        else cout <<  a[i] << ' ';

        turn ^= 1;
    }
    cout << '\n';

    // o = 0; e = 0;
    // n++;
    // find_xor();
    // cout << RED << o << ' ' << GREEN << e << RESET << '\n';

}

int main(){

    int tt; cin >> tt;
    while(tt--) solve();
    
    return 0;
}