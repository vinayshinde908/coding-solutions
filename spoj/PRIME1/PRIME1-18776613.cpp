#include <iostream>
#include <math.h>
using namespace std;

int primes[1000000];
int k=0;

void sieve(int n)
{
  bool pri[n+1];
  for(int i=0;i<=n;i++)
  pri[i]=true;
  int temp=sqrt(n);
  for(int i=2; i<=temp;i++)
  {
    if(pri[i]==true)
    {
      for(int j=i*2;j<=n;j=j+i)
      {
        pri[j]=false;
      }
    }
  }
    for(int i=2;i<=n;i++)
    {
      if(pri[i])
      {
        primes[k++]=i;
      }
    }
}

void print(int n1, int n2)
{
  if (n1==1) {
    n1=2;
  }
  for(;n1<=n2;n1++)
  {
    int temp=sqrt(n1);
    int flag=0;
    for(int i=0;primes[i]<=temp;i++)
    {
      if(n1%primes[i]==0)
      {
        flag=1;
        break;
      }
    }
    if(flag==0)
    cout<<n1<<endl;
  }
  cout<<endl;
}
int main()
{
  int cases;
  cin>>cases;
  while(cases){
  int n,m;
    cin>>n>>m;
    sieve(32000);
    print(n,m);
    cases--;
}
}
