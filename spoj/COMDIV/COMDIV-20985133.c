#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cstdio>
#include <stack>
using std::string;

static struct IO {
    char tmp[1 << 10];

    // fast input routines
    char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
    inline char nextChar() { return cur = getc_unlocked(stdin); }
    inline char peekChar() { return cur; }

    inline operator bool() { return peekChar(); }
    inline static bool isBlank(char c) { return (c < '-' && c); }
    inline bool skipBlanks() { while (isBlank(nextChar())); return peekChar() != 0; }

    inline IO& operator >> (char & c) { c = nextChar(); return *this; }

    inline IO& operator >> (char * buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar())) *(buf++) = peekChar();
            } *(buf++) = 0; } return *this; }

    inline IO& operator >> (string & s) {
        if (skipBlanks()) {	s.clear(); s += peekChar();
            while (!isBlank(nextChar())) s += peekChar(); }
        return *this; }

    inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;	}

#define defineInFor(intType) \
	inline IO& operator >>(intType & n) { \
		if (skipBlanks()) { \
			int sign = +1; \
			if (peekChar() == '-') { \
				sign = -1; \
				n = nextChar() - '0'; \
			} else \
				n = peekChar() - '0'; \
			while (!isBlank(nextChar())) { \
				n += n + (n << 3) + peekChar() - 48; \
			} \
			n *= sign; \
		} \
		return *this; \
	}

    defineInFor(int)
    defineInFor(unsigned int)
    defineInFor(long long)

    // fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
    inline void putChar(char c) { putc_unlocked(c, stdout); }
    inline IO& operator << (char c) { putChar(c); return *this; }
    inline IO& operator << (const char * s) { while (*s) putChar(*s++); return *this; }

    inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

    char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
    inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
	inline char * toString(intType n) { \
		char * p = (tmp + 30); \
		if (n) { \
			bool isNeg = 0; \
			if (n < 0) isNeg = 1, n = -n; \
			while (n) \
				*--p = (n % 10) + '0', n /= 10; \
			if (isNeg) *--p = '-'; \
		} else *--p = '0'; \
		return p; \
	} \
	inline IO& operator << (intType n) { return (*this) << toString(n); }

    defineOutFor(int)
    defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
using namespace std;
typedef long long ll;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (ll i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REPI(i, j) for(ll i=1; i<=j; i++)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vl;
const ll mod = 1000000007;

void solve();

int main() {
    //freopen("../input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    solve();
    return 0;
}
const int MAXN = 1000001;

int spf[MAXN];

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

int getfactors(int n) {
    map<int, int> m;
    while(n!=1){
        m[spf[n]]++;
        n/=spf[n];
    }
    int res = 1;
    for(auto it: m){
        res*=(it.second+1);
    }
    return res;
}
int func(int a){
    return getfactors(a);
}

int gcd(int a, int b)
{
    /* GCD(0, b) == b; GCD(a,0) == a, GCD(0,0) == 0 */
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    /*Finding K, where K is the greatest power of 2
      that divides both a and b. */
    int k;
    for (k = 0; ((a | b) & 1) == 0; ++k)
    {
        a >>= 1;
        b >>= 1;
    }
 
    /* Dividing a by 2 until a becomes odd */
    while ((a & 1) == 0)
        a >>= 1;
 
    /* From here on, 'a' is always odd. */
    do
    {
        /* If b is even, remove all factor of 2 in b */
        while ((b & 1) == 0)
            b >>= 1;
 
        /* Now a and b are both odd. Swap if necessary
           so a <= b, then set b = b - a (which is even).*/
        if (a > b)
            swap(a, b);   // Swap u and v.
 
        b = (b - a);
    }   while (b != 0);
 
    /* restore common factors of 2 */
    return a << k;
}

void solve() {
    sieve();
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        int g = gcd(a, b);
        cout<<func(g)<<endl;
    }
}