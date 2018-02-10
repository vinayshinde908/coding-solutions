#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>

using namespace std;
typedef long long ll;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REPI(i,j) for(int i=1; i<=j; i++)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back
#define si(x)    scanf("%d",&x)
#define sl(x)    scanf("%lld",&x)
#define ss(s)    scanf("%s",s)
#define pi(x)    printf("%d\n",x)
#define pl(x)    printf("%lld\n",x)
#define ps(s)    printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vl;
const int mod = 1000000007;

void solve();

int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}

void recur(int a[], int x, int n){
    if(x==0) return;
    else {
        int temp=a[x];
        a[x]=a[x-1];
        a[x-1]=temp;
        recur(a,x-1,n);
    }
}

void recur1(int a[], int x, int n){
    if(x==0) return;
    else{
        recur1(a,x-1, n);
        int temp=a[x];
        a[x]=a[x-1];
        a[x-1]=temp;
    }
}
void solve() {
    int a;
    cin>>a;
    int arr[a];
    REP(i,a)
        arr[i]=i+1;
    recur(arr,a-1,a);
    REP(i,a)
        cout<<arr[i]<<" ";
    cout<<endl;
    return;
}