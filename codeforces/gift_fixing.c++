#include <algorithm>
#include <bits/stdc++.h>
#include <array>
using namespace std;


main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        long long int count=0;
        cin >> n;
        long long int arr1[n];
        long long int arr2[n];

        for(int i=0; i<n; i++){
            cin >> arr1[i];
        }
        for(int j=0; j<n; j++){
            cin >> arr2[j];
        }

        long long int n1 = sizeof(arr1)/sizeof(arr1[0]);
        long long int n2 = sizeof(arr2)/sizeof(arr2[0]);

        long long int min_n1 = *min_element(arr1, arr1 + n1);
        long long int min_n2 = *min_element(arr2, arr2 + n2);
        

        for(int x=0; x<n; x++){
            long long int temp1 = arr1[x]-min_n1;
            long long int temp2 = arr2[x]-min_n2;
            if(temp1>temp2){
                count+=temp1;
            }
            else{
                count +=temp2;
            }
        }


        cout <<count<<endl;
    }

    return 0;
}