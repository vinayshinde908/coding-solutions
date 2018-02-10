#include<iostream>
#include "stdio.h"
#include<algorithm>
#include "string.h"
#include<map>
#include "math.h"

using namespace std;
int main(){
    long i, j;
    int t;
    cin>>t;
    while(t--){
       long n, temp;
       cin>>n;
       long arr[2*n];
       for(i=0; i<2*n ;i++){
           cin>>arr[i];
       }
       sort(arr, arr+2*n);
       cout<<arr[n+n/2]<<endl;
       for(i=0; i<n ;i++){
           cout<<arr[i]<<" "<<arr[n+i]<<" ";
       }
       cout<<endl;
    }
    return 0;
}
