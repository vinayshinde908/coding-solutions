#include <iostream>
#include<algorithm>
#include "math.h"
#include<map>
#include<set>
using namespace std;
int main() {
    long long sum, t,n;
    double a, b, c, slope, C;
    cin>>t;
    while(t--){
        map< double, set<double> > ma;
        sum=0;
        cin>>n;
        while(n--){
            cin>>a>>b>>c;
            if(b==0)
            {
                slope=10000000000;
                C=-c/a;
            }
            else{
                slope=-a/b;
                C=-c/b;
            }
            ma[slope].insert(C);
        }
        for(map< double ,set< double> >::iterator it=ma.begin();
        it!=ma.end();
        ++it)
        {
            if(it->second.size()>sum)
            sum=it->second.size();
        }
        cout<<sum<<endl;
    }
    return 0;
}
