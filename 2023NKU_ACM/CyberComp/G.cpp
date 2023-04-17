#include <iostream>
//#include <cstring>
#include <algorithm>
//#include <sstream>
//#include <cmath>
//#include <bitset>
//#include <iomanip>
//#include <string>

//#include <vector>
//#include <list>
//#include <queue>
//#include <stack>
//#include <set>
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
using namespace std;

#define LL long long
#define ULL unsigned long long
typedef pair<int,int> PII;

const int N = 1e5+10;
int n,m;
PII a[N];
double seg[N];
LL sumk[N],sumb[N];
bool cmp(PII &a, PII &b)
{
    double sega = (double)a.second/a.first, segb = (double)b.second/b.first;
    return sega<segb;
}

int get_uppper(int x)
{
    int l=1,r=n+1;
    while(l<r)
    {
        int mid = l+r>>1;
        if(seg[mid]>x) r=mid;
        else l=mid+1;
    }
    return l;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i].first>>a[i].second;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        seg[i] = (double)a[i].second/a[i].first;
        // cout<<seg[i]<<endl;
        sumk[i] = sumk[i-1]+a[i].first;
        sumb[i] = sumb[i-1]+a[i].second;
    }

    for(int x=1;x<=m;x++)
    {
        int idx=get_uppper(x);
        if(idx==n+1)
        {
            cout<<sumk[n]*x-sumb[n];
            if(x!=m)cout<<' ';
            continue;
        }
        // cout<<idx<<endl;
        LL k_p = sumk[idx-1], b_p=sumb[idx-1];
        LL k_n = -(sumk[n]-sumk[idx-1]), b_n = -(sumb[n]-sumb[idx-1]);
        cout<<k_p*x-b_p + k_n*x-b_n<<' ';
    }
	return 0;
}