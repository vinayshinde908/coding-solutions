#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;


int power(int a,int b,int m = MOD){
	if(b == 0) return 1;
	if(b == 1) return a;
	int x = power(a,b/2,m)%m;
	x = (x*x)%m;
	if(b%2) return (x*a)%m;
	return x;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int e, s, f, m, ee, ss, ff, mm;
	int a = 0, b = 0, c = 0, d = 0;
	int make1, make2, make3, make4;
	int maxi;


	while(true) {
		
		cin >> e >> s >> f >> m >> ee >> ss >> ff >> mm; 


		if(e == -1 && s == -1 && f == -1 && m == -1 && ee == -1 && ss == -1 && ff == -1 && mm == -1) break;	
		make1 = (int) ceil((float) e  / (float) ee );
		make2 = (int) ceil((float) s  / (float) ss );
		make3 = (int) ceil((float) f  / (float) ff );
		make4 = (int) ceil((float) m / (float) mm );
		

		maxi = max(max(make1,make2), max(make3,make4));
		a = 0, b = 0, c = 0, d = 0;
		a += (maxi * ee) - e;
		b += (maxi * ss) - s;
		c += (maxi * ff) - f;
		d += (maxi * mm) - m;
		cout << a << " " << b << " " << c << " " << d << endl;
	}
	return 0;
}