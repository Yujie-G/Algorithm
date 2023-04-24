#include <iostream>
#include <stack>
using namespace std;
#define LL long long
const int N = 35;

int n;
int w[N];
int ans[N][N];
LL f[N][N];
LL dp(int h,int t)
{
    if(h>t)return 1;
    if(h==t){
        f[h][t]=w[h];
        return f[h][t];
    }
    LL &tmp=f[h][t];
    if(tmp)return tmp;
    int idx=-1;

    for(int i=h;i<=t;i++)
    {
        LL cur=w[i]+dp(h,i-1)*dp(i+1,t);
        if(cur>tmp) tmp=cur,idx=i;
    }
    ans[h][t]=idx;
    return tmp;
}

void outANS(int hh,int tt)
{
    if(hh>tt)return;
    if(hh==tt){
        cout<<hh<<' ';
        return;
    }
    int i = ans[hh][tt];
    cout<<i<<' ';
    outANS(hh,i-1),outANS(i+1,tt);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>w[i];


    cout<<dp(1,n)<<endl;
    outANS(1,n);

    return 0;
}