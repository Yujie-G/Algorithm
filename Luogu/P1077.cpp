// 有 nn 个数（c1,c2,...,cn​）， 0⩽ci⩽ai0⩽ci​⩽ai​,求有多少种方案数使∑i=1nci=mi=1∑n​ci​=m。
#include <iostream>

using namespace std;
const int N = 120,M =120,  mod = 1e6+7;
int f[N][M];
int a[N];
int main()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<=min(j,a[i]);k++)
            {
                f[i][j] =(f[i][j] + f[i-1][j-k]) %mod;
            }
        }
    }
    cout<<f[n][m];
    return 0;
}