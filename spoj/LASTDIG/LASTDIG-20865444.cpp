#include<iostream>
using namespace std;

long long last_digit(long long a, long long b)
{
  if(b==0) return 1;
  a=a%10;
  b=(b-1)%4;
  long long last=a;
  for(long long i=1;i<=b;i++)
    {
      last=last*a;
      last=last%10;
    }
  return last;
}

int main()
{
  long long n,m,cases;
  cin>>cases;
  while(cases)
    {
  cin>>n>>m;
  cout<<last_digit(n,m)<<endl;
  cases--;
    }
  return 0;
}
