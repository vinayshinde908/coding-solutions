#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int t, i, j, n, m, sum, low;
	cin>>t;
	while(t--){
	    sum=0;
	  cin>> n;
	  int a[n],b[n];
	  for(i=0; i< n; i++)
	  cin>>a[i];
	  for(i=0; i<n; i++)
	  cin>>b[i];
	  sort(a, a+n);
	  sort(b, b+n);
	  for(i=0; i<n; i++)
	  sum+=a[i]*b[n-1-i];
	  cout<< sum<< endl;
	  
	}
	return 0;
}
