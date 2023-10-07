#include <bits/stdc++.h>
using namespace std;

int binarySearch(int x, int arr[], int low, int high){
    int mid = (low+high)/2;
    if(x==arr[mid]){
        return mid;
    }
    else if(x>arr[mid]){
        return binarySearch(x, arr, mid+1, high);
    }
    else if(x<arr[mid]){
        return binarySearch(x, arr, low, mid-1);
    }
    return 0;
}

main(){
    int low = 0;
    int high = 15;
    int arr[15] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 1400, 1500};
    int element_to_find;
    cin >> element_to_find;
    cout << binarySearch(element_to_find, arr, low, high);
    return 0;
}