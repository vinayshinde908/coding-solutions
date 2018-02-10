#include <iostream>

using namespace std;

int squares(int n)
{
  return (n*(n+1)*(2*n+1))/6;
}

int main()
{
  int n;
  cin>>n;
  while(n!=0)
  {
    cout<<squares(n)<<endl;
    cin>>n;
  }
  return 0;
}
