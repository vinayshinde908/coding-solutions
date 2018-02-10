#include<iostream>
using namespace std;

int last_digit(int a, long int b)
{
  if(b==0) return 1;
  a=a%10;
  b=(b-1)%4;
  int last=a;
  for(long int i=1;i<=b;i++)
    {
      last=last*a;
      last=last%10;
    }
  return last;
}

int main()
{
  int n,m,cases;
  cin>>cases;
  while(cases)
    {
  cin>>n>>m;
  cout<<last_digit(n,m)<<endl;
  cases--;
    }
  return 0;
}
