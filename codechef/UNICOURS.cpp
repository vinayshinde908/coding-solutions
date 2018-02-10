#include<iostream>
#include "stdio.h"
#include<algorithm>
#include "string.h"
#include<map>

using namespace std;
int main(){
    long i, j;
    int t;
    cin>>t;
    while(t--){
       long n, temp;
       cin>>n;
       long ans=0;
       long max=0;
       for(i = 0 ; i< n; i++){
           cin>>temp;
           if(temp> max) max=temp;
       }
       cout<< n-max<< endl;
    }
}
