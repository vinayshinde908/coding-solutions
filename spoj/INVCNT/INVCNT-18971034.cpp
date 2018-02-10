#include<iostream>

using namespace std;

long long merge(long long [], long long ,long long ,long long);
long long merge_count(long long arr[], long long left, long long right) {
  long long mid, inv_count = 0;
  if (right > left)
	  {
		  mid = (right + left)/2;
		  inv_count  = merge_count(arr, left, mid);
		  inv_count += merge_count(arr, mid+1, right);
		  inv_count += merge(arr, left,mid+1, right);
	  }
  return inv_count;
}

long long  merge(long long arr[], long long left, long long mid, long long right) {
	long long i=left, j=mid;
	long long k=left,invcount=0;
	long long temp[200000];
	while (i<=mid-1 && j<=right) {
		if (arr[i]<arr[j]) {
			temp[k++]=arr[i++];
		}
		else {
			temp[k++]=arr[j++];
			invcount+=(mid-i);
		}
	}
	while (i <= mid-1 )
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i=left; i <= right; i++)
		arr[i] = temp[i];
	return invcount;
}


int main()
{
	int cases;
	cin >> cases;
	while (cases--) {
		long long n;
		cin >> n;
		long long arr[n];
		for (long long i = 0; i < n ; i++) {
			cin >> arr[i];
		}
		cout << merge_count(arr, 0, n-1) << "\n";
	}
	return 0;
}
