#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define GC getchar_unlocked()
int scan()
{
    int ret=0,sign=1;
    int ip=GC;
    for(;ip<'0'||ip>'9';ip=GC);
    for(;ip>='0'&&ip<='9';ip=GC)
        ret=ret*10+ip-'0';
    return (ret*sign);
}


const int N = 1000001;
const int Q = 200010;
int T[N],a[Q];
pair<int,int> p1[N];

struct Query
{
    int idx,i,j,k;
}p2[Q];

bool sort_cond1(const pair<int,int> &q1,const pair<int,int> &q2)
{
    return q1.first>q2.first;
}

bool sort_cond2(const Query &q1,const Query &q2)
{
    return q1.k>q2.k;
}

void update(int idx)
{
    while(idx<=N)
    {
        T[idx]++;
        idx += (idx & -idx);
    }
}
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum += T[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int query(int l,int r)
{
    return read(r)-read(l-1);
}

int main()
{
    //freopen("../input.txt", "r", stdin);
    int n,q,i,j,k;
    n=scan();
    for(i=0;i<n;i++)
    {
        p1[i].first=scan();
        p1[i].second=i+1;
    }
    q=scan();
    sort(p1,p1+n,sort_cond1);
    for(i=0;i<q;i++)
    {
        p2[i].i=scan();
        p2[i].j=scan();
        p2[i].k=scan();
        p2[i].idx=i;
    }
    sort(p2, p2+q, sort_cond2);
    i=0,j=0;
    while(i<q)
    {
        k=p2[i].k;
        while(j<n && p1[j].first>k)
        {
            update(p1[j].second);
            j++;
        }
        while(i<q && p2[i].k==k)
        {
            a[p2[i].idx]=query(p2[i].i,p2[i].j);
            i++;
        }
    }
    for(i=0;i<q;i++) printf("%d\n",a[i]);
    return 0;
}