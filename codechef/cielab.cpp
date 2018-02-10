#include<iostream>

using namespace std;

int main()
{
	int a, b;
	cin>>a>>b;
	int res=a-b;
	if (res%10 !=9) {
		res+=1;
	}else {
		res-=1;
	}
	cout<<res<<endl;
	return 0;
}
