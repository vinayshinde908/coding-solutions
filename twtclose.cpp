#include <stdio.h>
#include<iostream>
#include <string.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n>>m;
	int arr[n]={0};
	getchar();
	for (int i = 0; i < m ; i++) {
		char s[100];
		cin>>s;
		if(strcmp(s, "CLOSEALL")==0)
			{
				for (int j = 0; j < n ; j++) {
					arr[j]=0;
				}
	
}else {
			int n;
			cin>>n;
			if(arr[n-1]==0) arr[n-1]=1;
			else
				arr[n-1]=0;
		}
		int count=0;
		for (int j = 0; j < n ; j++) {
			if(arr[j]==1) count++;
		}
		cout<<count<<endl;
	}

	return 0;
}
