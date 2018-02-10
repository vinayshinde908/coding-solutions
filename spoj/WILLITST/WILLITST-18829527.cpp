#include <iostream>
#include <math.h>
using namespace std;

int main( )
{
	long double n;
	cin>>n;
	if(log2l(n)-(long long)log2l(n)==0)
		{
			cout<<"TAK"<<endl;
		}
	else cout<<"NIE"<<endl;
	return 0;
}
