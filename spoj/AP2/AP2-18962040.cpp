#include<iostream>

using namespace std;

int main()
{
	int cases;
	cin>>cases;
	while (cases--) {
		long long f3, l3, sum;
		cin >> f3>> l3>> sum;
		long long n=(sum*2)/(f3+l3);
		long long d=(l3-f3)/(n-5);
		long long a= f3 -2*d;
		cout << n << "\n";
		for (long long i = 0; i < n ; i++) {
			cout << a << " ";
			a=a+d;
		}
		cout << "\n";
	}
	return 0;
}
