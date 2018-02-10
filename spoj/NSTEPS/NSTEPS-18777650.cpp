#include <iostream>
using namespace std;

int number(int x, int y)
{
  if(x==y)
  {
    if(x%2==0 && y%2==0)
    {
      return x*2;
    }
    else
    {
      return x+y-1;
    }

  }else
  {
    if(x%2==0 && y%2==0)
    {
      if(x==y+2)
      {
        return x+y;
      }
    }
    else if(x%2==1 && y%2==1 && x==y+2)
    {
      return x+y-1;
    }

  }
  return -1;
}

int main()
{
  int cases;
  cin>>cases;
  while(cases)
  {
    int x,y;
    cin>>x>>y;
    int res=number(x,y);
    if(res==-1)
    cout<<"No Number"<<endl;
    else
    cout<<res<<endl;
    cases--;
  }
}
