#include<iostream>
using namespace std;
#define ll long long

int main(){
  ll a, b;
  scanf("%lld %lld",&a, &b);
  ll res=a/b;
  if(res%2==1){
    printf("YES");
  }else{
    printf("NO");
  }
  return 0;
}