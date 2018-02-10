#include<iostream>

using namespace std;

int main()
{
	int cases;
	cin>>cases;
	while (cases--) {
		int n;
		cin>>n;
		long res=0;
		while (n--) {
			int sum, id;
			cin>>id>>sum;
			res+=id-sum;
		}
		cout << res << "\n";
	}
	return 0;
}
