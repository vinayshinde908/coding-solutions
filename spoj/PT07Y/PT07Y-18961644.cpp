#include<iostream>
#include <cstring>

using namespace std;
int no=0;

void cycle(int *arr, int n, int v[], int s) {
	no++;
	v[s]=1;
	for (int i = 0; i < n ; i++) {
		if(*((arr+s*n)+i)==1 && v[i]==0)
			cycle(arr, n, v, i);
	}
}

int main()
{
	int m, n;
	cin >> n>> m;
	int v[n];
	int arr[n][n];
	memset(arr, 0, sizeof(arr));
	memset(v, 0, sizeof(v));
	if(m == n-1){
		for (int i = 0; i < m ; i++) {
			int temp1, temp;
			cin>>temp1>>temp;
			arr[temp1-1][temp-1]=1;
			arr[temp-1][temp1-1]=1;
		}
		cycle((int *)arr, n, v, 0);
	}
	if (no!=n) {
		cout << "NO" << "\n";
	}
	else {
		cout << "YES" << "\n";	
	}
	return 0;
}
