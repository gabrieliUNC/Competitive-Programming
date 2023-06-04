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

vector<int> odd;
vector<int> even;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    int size = n % 2 == 0 ? n / 2 : n / 2 + 1;

    odd.resize(size); odd.clear();
    even.resize(n / 2); even.clear();
    cout << "----------------------------------\n";


    //test odd
    for(int i = 0; i < size; ++i){
        int elt; cin >> elt;
        odd.push_back(elt);
    }

    //test even
    for(int i = 0; i < n / 2; ++i){
        int elt; cin >> elt;
        even.push_back(elt);
    }

    // odd even array
    auto e_start = even.begin();
    auto o_start = odd.begin();
    int i = 0;

    while(i++ < n){
        if(!(i % 2)){
            cout << GREEN << *e_start << RESET << ' ';
            e_start++;
        }
        else{
            cout << RED << *o_start << RESET << ' ';
            o_start++;
        }
    }

    cout << "===============================\n";

    i = 0;
    e_start = even.begin();
    o_start = odd.begin();
    int e = 0;
    int o = 0;

    while(i++ < n){
        if(!(i % 2)){
            e ^= *e_start;
            cout << BOLDGREEN << e << RESET << ' ';
            e_start++;
        }
        else{
            o ^= *o_start;
            cout << BOLDRED << o << RESET << ' ';
            o_start++;
        }
    }

    return 0;
}