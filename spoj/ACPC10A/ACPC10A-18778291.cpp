#include <iostream>
using namespace std;

void progression(int x, int y, int z)
{
  if(y-x==z-y)
  {
    cout<<"AP "<<z+(z-y)<<endl;
    return;
  }
  else if(y/x==z/y)
  {
    cout<<"GP "<<z*((float)z/y)<<endl;
  }
}

int main()
{
  int x,y,q;
  cin>>x>>y>>q;
  while(x!=0 || y!=0 || q!=0)
  {
  progression(x,y,q);
  cin>>x>>y>>q;
  }
  return 0;
}
