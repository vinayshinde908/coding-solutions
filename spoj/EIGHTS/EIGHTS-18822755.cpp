#include <iostream>
using namespace std;

long long funct(long long k)
{
	int mod= k%4;
	switch(mod)
		{
		case 1: return (k/4)*1000+192;
		case 2: return (k/4)*1000+442;
		case 3: return (k/4)*1000+692;
		case 0: return (k/4-1)*1000+942;
		}
	
}
 


int main( )
{
	int cases;
	cin>>cases;
	while(cases--)
		{
			long long k;
			cin>>k;
			cout<<funct(k)<<endl;
		}
	return 0;
}
