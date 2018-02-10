#include <iostream>
using namespace std;

int count(int n)
{
  int res=0;
  while(n>=5)
  {
    res=res+(n/5);
    n=n/5;
  }
  
  return res;
}

int main()
{
  int cases;
  cin>>cases;
  while(cases)
  {
    int n;
    cin>>n;
    cout<<count(n)<<endl;
    cases--;
  }
  return 0;
}
