#include<iostream>

using namespace std;

void sort(int arr[], int n) {
	for (int i = 0; i < n-1 ; i++) {
		for (int j = 0; j < n-1 ; j++) {
			if (arr[j]<arr[j+1]) {
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main()
{
	int cases;
	cin >> cases;
	while (cases--) {
		int n;
		cin >> n;
		int men[n],women[n];
		for (int i = 0; i < n ; i++) {
			cin>>men[i];
		}
		for (int i = 0; i < n ; i++) {
			cin>>women[i];
		}
		sort(men, n);
		sort(women, n);
		int sum=0;
		for (int i = 0; i < n ; i++) {
			sum= sum+(men[i]* women[i]);
		}
		cout << sum << "\n";
	}
	return 0;
}
