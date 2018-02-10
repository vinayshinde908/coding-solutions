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
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef vector<int>		vi;
typedef vector<ll>		vl;
const int mod = 1000000007;

int main()
{
    //freopen("../input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[6][6];
    for(int i=0; i<6; i++)
        for(int j=0; j<6; j++)
            a[i][j]=1;
    FOR(i, 1, 4, 1)
        FOR(j, 1, 4, 1){
            int temp;
            cin>>temp;
            temp%=2;
            if(temp==1){
                a[i-1][j]=1-a[i-1][j];
                a[i][j-1]=1-a[i][j-1];
                a[i][j]=1-a[i][j];
                a[i][j+1]=1-a[i][j+1];
                a[i+1][j]=1-a[i+1][j];
            }
        }
    FOR(i,1,4,1){
        FOR(j,1,4,1)
            cout<<a[i][j];
        cout<<endl;
    }
	return 0;
}