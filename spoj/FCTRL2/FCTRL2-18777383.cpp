#include <iostream>
using namespace std;

int arr[1024],digit=0;

void fact(int n)
{
    int carr=0;
    digit=1;
    arr[0]=1;
    while(n!=0)
    {
      for(int i=0;i<digit;i++)
      {
        int res=arr[i]*n+carr;
        arr[i]=res%10;
        carr=res/10;
      }
      while(carr!=0)
      {
        arr[digit]=carr%10;
        digit++;
        carr=carr/10;
      }
      n--;
    }
    for(int i=digit-1;i>=0;i--)
    cout<<arr[i];
    cout<<endl;
}
int main()
{
  int cases;
  cin>>cases;
  while(cases)
  {
    int n;
    cin>>n;
    fact(n);
    cases--;
  }
  }
