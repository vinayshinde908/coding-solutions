#include <iostream>
using namespace std;

int rev(int n){
	int r,temp=0;
	while(n!=0)
	{
		r=n%10;
		temp=temp*10+r;
		n=n/10;
	}
	return temp;
}

int main() {
	int cases;
	cin>>cases;
	while(cases)
	{
		int n1, n2;
		cin>>n1>>n2;
		cout<<rev(rev(n1)+rev(n2))<<endl;
		cases--;
	}	
	return 0;
}