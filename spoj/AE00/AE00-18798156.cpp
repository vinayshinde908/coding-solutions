#include <iostream>
using namespace std;

int rectangle(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	int res=0;
	for(int i=1; i<=n;i++)
		for(int j=i; j<=n ; j++)
			if(i*j <= n)
				res++;
	return res;
}
int main()
{
	int n;
	cin>>n;
	cout << rectangle(n) << "\n";
	return 0;
}
