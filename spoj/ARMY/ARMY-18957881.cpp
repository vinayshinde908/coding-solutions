#include<iostream>

using namespace std;

int main()
{
	int cases;
	cin>>cases;
	while (cases--) {
		int n, m;
		cin>>n>>m;
		int temp;
		int maxg=0, maxm=0;
		for (int i = 0; i < n ; i++) {
			cin>>temp;
			if(temp > maxg) maxg=temp;
		}
		for (int i = 0; i < m ; i++) {
			cin>>temp;
			if(temp > maxm) maxm=temp;
		}
		if(maxm > maxg)
			cout << "MechaGodzilla" << "\n";
		else
			cout << "Godzilla" << "\n";
	}
	return 0;
}
