#include  <iostream>

using namespace std;
#define LL long long
const int N = 1e5+10;

int n;
LL s[N];
int a[N];

LL ans=0;
void solve(int l,int r)
{
    if(l>=r)return;
    int ll = l, rr=r;
    LL tmpS = s[r]-s[l-1]>>1;
    while(ll<rr)
    {
        int mid = ll+rr>>1;
        LL c = s[mid]-s[l-1];
        if(tmpS>c)ll = mid+1;
        else rr=mid;
    }
    if(s[ll]-s[l-1]-tmpS>tmpS-s[ll-1]+s[l-1])ll--;
    // cout<<"ll: "<<ll<<endl;
    ans+=(s[ll]-s[l-1]) * (s[r]-s[ll]);
    solve(l,ll),solve(ll+1,r);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i] = s[i-1]+a[i];
    }
    solve(1,n);
    cout<<ans;
    return 0;
}