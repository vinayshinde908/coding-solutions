#include<iostream>
#include<math.h>
 
using namespace std;
 
int seg[1000000*3]={0}, lazy[1000000*3]={0};
 
int query(int low, int high, int qlow, int qhigh, int pos){
	
	if(lazy[pos]!=0){ //Check if the current position needs to be fipped, or not
		lazy[pos]=0;
		seg[pos]=high-low+1-seg[pos];
		if(low!=high) //Change the lazy tree for child nodes also, if any
		{
			lazy[pos*2+1]=(lazy[pos*2+1]+1)%2;
			lazy[pos*2+2]=(lazy[pos*2+2]+1)%2;
		}
	}
if (low > qhigh || high < qlow) { // No overlap 
		return 0;
	}
	if (qlow <= low && qhigh >= high) { //Total Overlap
		return seg[pos];
	}
	int mid=(low+high)/2;
	return query(low, mid, qlow, qhigh, pos*2+1)+query(mid+1, high, qlow, qhigh, pos*2+2); // partial overlap
}
 
int update(int low, int high, int qlow, int qhigh, int pos){
	
	if(lazy[pos]!=0){
		lazy[pos]=0;
		seg[pos]=high-low+1-seg[pos];
		if(low!=high)
		{
			lazy[pos*2+1]=(lazy[pos*2+1]+1)%2;
			lazy[pos*2+2]=(lazy[pos*2+2]+1)%2;
		}
	}
if (low > qhigh || high < qlow) {
		return seg[pos];
	}
	if (qlow <= low && qhigh >= high) {
		seg[pos]=high-low+1-seg[pos];
		if(low!=high) //Change the lazy tree for child nodes also, if any
		{
			lazy[pos*2+1]=(lazy[pos*2+1]+1)%2;
			lazy[pos*2+2]=(lazy[pos*2+2]+1)%2;
		}
		return seg[pos];
	}
	int mid=(low+high)/2;
	seg[pos]=update(low, mid, qlow, qhigh, pos*2+1)+update(mid+1, high, qlow, qhigh, pos*2+2);
	return seg[pos];
}
int main()
{
	long long n, q;
	cin >> n>> q;
	while (q--) {
		int com, a,b;
		cin>>com>>a>>b;
		if (com==1) {
			cout << query(0, n-1, a, b, 0) << "\n";
		}
		else if (com==0) {
			update(0, n-1, a , b , 0);
		}
	}
	
	return 0;
} 
