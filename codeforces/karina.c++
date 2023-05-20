#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;

int main(){
    int num_test_cases; cin >> num_test_cases;

    

    while(num_test_cases--){
        int size; cin >> size;
        vector<int> array(size);

        for(int i = 0; i < size; ++i) cin >> array[i];

        sort(array.begin(), array.end(), greater<int>());

        ll first = array[0] * array[1];

        sort(array.begin(), array.end());

        ll second = array[0] * array[1];

        cout << (first > second ? first : second) << '\n';

    }


    return 0;
}