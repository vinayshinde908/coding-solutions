#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

void funct(){
	long n;
	char a[20],b,c[20],d,e[20];
	cin>>a>>b>>c>>d>>e;
	long int x=0,y=0,z=0;
	int found=0;
	for (int i=0; i< strlen(a); i++) {
		if(!isdigit(a[i]))
			{if(found == 0)
					found=1;}
		else
			x=x*10+(a[i]-'0');
	}
	for (int i=0; i< strlen(c); i++) {
		if(!isdigit(c[i])){
		   if(found == 0)
			   found=2;}
		else
			y=y*10+(c[i]-'0');
	}
	for (int i=0; i< strlen(e); i++) {
		if(!isdigit(e[i])){
		   if(found == 0)
			   found=3;}
		else
			z=z*10+(e[i]-'0');
	}
	switch(found)
		{
		case 1: n= z-y;
			cout<<n<<" + "<<y<<" = "<<z<<endl;
			break;
		case 2: n= z-x;
			cout<<x<<" + "<<n<<" = "<<z<<endl;
			break;
		case 3: n= x+y;
			cout<<x<<" + "<<y<<" = "<<n<<endl;
			break;
		}
	return;
}

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	funct();

}
