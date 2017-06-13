#include <iostream>
#include<algorithm>
#include "math.h"
using namespace std;

long long compute(long long n){
    n=n*2;
    long long temp;
    temp=ceil((-1+sqrt(1-(4*(-n))))/2);
    return temp;
}


int main() {
	long long t, i, j, n, m, sum, low;
	cin>>t;
	while(t--){
	  cin>>n;
	  sum=compute(n);
	  cout<<sum<<endl;
	}
	return 0;
}
