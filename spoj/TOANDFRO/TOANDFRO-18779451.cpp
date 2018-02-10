#include <iostream>
#include<string.h>
using namespace std;

void print(int n)
{
  int k=0,flag=0;
  char temp[200];
  cin>>temp;
  int len=strlen(temp);
  char arr[len/n][n];
  for(int i=0;i<len/n;i++)
  {
    if(flag==0){
      flag=1;
      for(int j=0;j<n;j++)
      {
        arr[i][j]=temp[k++];
      }
    }
    else
    {
      flag=0;
      for(int j=n-1;j>=0;j--)
      {
        arr[i][j]=temp[k++];
      }
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<len/n;j++)
    {
      cout<<arr[j][i];

    }
  }
  cout<<endl;
}

int main()
{
  int n;
  cin>>n;
  while(n!=0)
  {
  print(n);
  cin>>n;
  }
  return 0;
}
