#include <iostream>
#include <string>

using namespace std;

int main(){
    int x;
	long long int y;
	long long int res;
	scanf("%d",&x);
	while(x--){
		scanf("%lld",&y);
		res=(y*(y+2)*(2*y+1))/8;
		printf("%lld\n",res);
	}
}