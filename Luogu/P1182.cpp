#include <iostream>
using namespace std;

const int N = 1e5+10;
int n,m;

int a[N];

bool check(int x)
{
    int tot=0,num=1;
    for(int i=1;i<=n;i++)
    {
        if(tot+a[i]<=x)tot+=a[i];
        else tot=a[i],num++;
    }
    return num>m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int l=0,r=1e9;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        l = max(l,a[i]);
    }
    while(l<=r)
    {
        int mid = (l+r)>>1;
        // cout<<l<<' '<<r<<' '<<mid<<endl;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<l;
    return 0;
}