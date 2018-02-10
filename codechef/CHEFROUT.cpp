#include<iostream>
#include "stdio.h"
#include<algorithm>
#include "string.h"

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int flag=0;
        char string[100000000];
        scanf("%s", string);
        long len=strlen(string);
        for(long i=0; i<len-1; i++){
            if(string[i]>string[i+1]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
}
