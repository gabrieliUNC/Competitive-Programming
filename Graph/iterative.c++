#include <bits/stdc++.h>
using namespace std;

main(){
    int arr[15] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 1400, 1500};
    int element_to_find;
    cin >> element_to_find;

    int low = 0;
    int high = 15;

    bool not_found = true;
    while(not_found){  
        int mid = (high + low) /2;
        if(arr[mid]==element_to_find){cout << mid; not_found = false;}
        else if(element_to_find>arr[mid]){low=mid+1;}
        else if(element_to_find<arr[mid]){high=mid-1;}
    }

}