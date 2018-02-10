//SPOJ submission 15725781 (C++ 4.3.2) plaintext list. Status: AC, problem ARITH2, contest SPOJ. By hmp_ism (hmp), 2015-11-28 08:42:58.
#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long long int num;
        cin>>num;
        long long int ans=num;
        while(true)
        {
            char ch;
            cin>>ch;
            if(ch=='=')
            break;
            cin>>num;
            if(ch=='/')
            ans/=num;
            else
            if(ch=='*')
            ans*=num;
            else if(ch=='+')
            ans+=num;
            else
            ans-=num;
        }
        cout<<ans<<"\n";
    }
	// your code goes here
	return 0;
}