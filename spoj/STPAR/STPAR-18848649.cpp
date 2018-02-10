#include <iostream>
using namespace std;


int funct(int n)
{
	int arr[n];
	for(int i=n-1;i>=0;i--)
		cin>>arr[i];
	int stack[n];
	int top=-1;
	int count=1,m=n;
	while(count<=m)
		{
		      if(n>0)
		     {
			     if(arr[n-1]==count)
				     {
					     n--;
					     count++;
					     continue;
				     }
			     if(top!=-1 && stack[top]==count)
				     {
					     top--;
					     count++;
					     continue;
				     }
			     if(top==-1)
				     {
					     stack[++top]=arr[n-1];
					     n--;
				     }
			     else
				     {
					     while(count!=arr[n-1] && arr[n-1]< stack[top] && n>0)
						     {
							     stack[++top]=arr[n-1];
							     n--;
						     }
					     if(n>0 && stack[top]<arr[n-1])
						     {
							     return 0;
						     }
				     }
				}
				else
				{
					while(top!=-1)
						{
							if(count==stack[top])
								{
									top--;
									count++;
								}
							else
								{
									return 0;
								}
				}
				}
		}
	return 1;
}


int main()
{
	int n;
	cin>>n;
	while(n!=0)
		{
			if(funct(n))
				cout<<"yes"<<endl;
			else
				cout<<"no"<<endl;
			cin>>n;
		}
	return 0;
	
}
