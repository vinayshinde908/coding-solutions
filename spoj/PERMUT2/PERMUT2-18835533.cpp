#include <iostream>
using namespace std;
int main( )
{int found=0,arr[200000],n;
	long cases;
	cin>>cases;
	while(cases)
		{
			found=0;
			for(int i=1;i<=cases;i++)
				{
					cin>>arr[i];
				}	
			for(int i=1; i<=cases;i++)
				{	
					if(arr[arr[i]]!= i)
						{ found=1;
							break;}
						}
					if(found==1)
						cout<<"not ambiguous"<<endl;
					else
						cout<<"ambiguous"<<endl;
					   
			cin>>cases;
		}
	return 0;
}
