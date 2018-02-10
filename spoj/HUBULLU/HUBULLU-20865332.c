#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
		int n, p;
		cin>>n>>p;
		if(!p) cout<<"Airborne wins.";
		else cout<<"Pagfloyd wins.";
		cout<<endl;
	}
	return 0;
}