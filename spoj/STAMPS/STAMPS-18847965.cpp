#include <iostream>
using namespace std;

void sort(long arr[], long n)
{
	for( long i= 0 ;i <n-1; i++)
		for(long j=i+1 ; j<n; j++)
			if(arr[i]<arr[j])
				{
					long temp=arr[i];
					arr[i]=arr[j];
					arr[j]=temp;
				}
	
}


int main()
{
	int coi=1;
	long cases;
	cin>>cases;
	while(cases--)
		{
			cout<<"Scenario #"<<coi++<<":"<<endl;
			long sum=0, n;
			long count=0,res=0;
			cin>>sum>>n;
			long arr[n];
			for(long i=0; i<n;i++)
				cin>>arr[i];
			sort(arr, n);
			for(long i=0; i<n;i++){
				if(res<sum)
					{
						res=res+arr[i];
						count++;
					}
			}
			if(res>=sum)
				cout<<count<<endl;
			else
				cout<<"impossible"<<endl;
		}
}
