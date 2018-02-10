#include <iostream>
using namespace std;

void funct()
{
	long long sum=0;
	long long c;
	cin>>c;
	for ( long long i=0; i< c; i++) {
		long long n;
		cin>>n;
		sum=(sum+n)%c;
	}
	if(sum)
		cout << "NO" << "\n";
	else
		cout << "YES" << "\n";
	
}


int main()
{
	int cases;
	cin>>cases;
	while(cases--)
		{
			funct();
		}
	return 0;
}
