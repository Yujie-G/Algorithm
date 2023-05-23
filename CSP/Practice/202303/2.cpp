#include <iostream>
#include <algorithm>

using namespace std;
#define LL long long
#define ULL unsigned long long
typedef pair<int,int> PII;
const int N = 1e5+11;

LL n,m,k;
PII a[N];

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    LL curt=a[n-1].first, curc=a[n-1].second;
    for(int i=n-2;i>=0;i--)
    {
        int t=a[i].first, c=a[i].second;
        LL cost = curc*(curt-t);
        if(cost>m){
            cout<<curt-m/curc;
            return 0;
        }
        m-=cost;
        curt=t;
        curc+=c;
    }
    LL cost = curc*(curt-k);
    if(cost<=m)
    {
        cout<<k;
    }
    else{
        cout<<curt-m/curc;
    }
    return 0;
}


