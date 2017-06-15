#include<iostream>
#include "stdio.h"
#include "math.h"

using namespace std;
const int MAX = 2e5 + 5;
long arr[MAX], sum[MAX], t[MAX];

void build (long index, long low, long high) {
	if (low == high)
		t[index] = sum[low];
	else {
	    long mid = (low + high) >>  1;
		build(index*2, low, mid);
		build (index*2+1, mid+1, high);
		t[index] = max(t[index*2] , t[index*2+1]);
	}
}

long rangeQuery (long index, long low, long high, long l, long r) {
	if (l > r)
		return 0;
	if (l == low && r == high)
		return t[index];
	long mid = (low + high) >>  1;
	return max(rangeQuery (index*2, low, mid, l, min(r,mid)),
		 rangeQuery (index*2+1, mid+1, high, max(l,mid+1), r));
}


int main(){
    long n, k, q;
    cin>>n>>k>>q;
    long N=2*n;
    long i;
    for(i=1; i<=n; i++){
        cin>>arr[i];
        arr[n+i]=arr[i];
    }
    sum[0]=0;
    for(i=1; i<=k ; i++){
        sum[i]=sum[i-1]+arr[i];
    }
    for(i=k+1; i<=N; i++){
        sum[i]=sum[i-1]+arr[i]-arr[i-k];
    }
    long pos=n+1;
    build(1, 1, N);
    while(q--){
        char c;
        cin>>c;
        if(c=='!'){
            pos-=1;
            if(pos==0) pos=n;
        }
        else{
            long res;
            if(k>=n){
                res=sum[n+1];
            }
            else{
                res=rangeQuery(1, 1, N, pos,  min(N, pos+n-k));
            }cout<<res<<endl;
        }
    }
    return 0;
}
