#include <iostream>
using namespace std;

int main() {
    bool n[1000003];
	int k, l, m;
	cin>>k>>l>>m;
	n[0] = false;
	n[1] = true, n[k] = true, n[l] = true;
	for(int i = 1; i<1000003; i++ ){
	    bool res = true;
        if(i>=k) res = (res and n[i-k]);
	    if(i>=l) res = (res and n[i-l]);
	    res = (res and n[i-1]);
	    if(res) n[i] = false;
	    else n[i] = true;
	}
	for(int i = 0; i< m; i++){
	    int temp;
	    cin>>temp;
	    if(n[temp]) cout<<"A";
	    else cout<<"B";
	}
	return 0;
}
