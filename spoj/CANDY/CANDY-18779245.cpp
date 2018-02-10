#include <iostream>
using namespace std;

int number(int n)
{
  int arr[n],count=0,res=0;
  for(int i=0;i<n;i++)
  {cin>>arr[i];
    count=count+arr[i];
  }
  if(count%n!=0) return -1;
  for(int i=0;i<n;i++)
  {
  while(arr[i]>(count/n))
  {
    arr[i]--;
    res++;
  }
  }
  return res;
}

int main()
{
  int n;
  cin>>n;
  while(n!=-1){
  cout<<number(n)<<endl;
  cin>>n;
  }
  return 0;
}
