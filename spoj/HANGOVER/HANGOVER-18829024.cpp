#include <iostream>
using namespace std;

void funct(float n)
{
	float i=1.0;
	float sum=0.0;
	while(sum<n){
		i=i+1.0;
		sum=sum+((float)1/i);
	}
	cout<<i-1<<" card(s)"<<endl;
	return;
}


int main(int argc, char *argv[])
{
	float n;
	cin>>n;
	while(n!=0.00){
	funct(n);
	cin>>n;
	}
	return 0;
}
