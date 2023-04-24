#include <iostream>
//#include <cstring>
//#include <algorithm>
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
const int N = 210;

int n;
int f[N][N];
int a[N];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=n+1;i<=2*n;i++)a[i]=a[i-n];
    for(int len=3;len<=n+1;len++)
    {
        for(int l=1;l+len-1<=2*n;l++)
        {
            int r = l+len-1;
            for(int k=l+1;k<r;k++)
            {
                f[l][r] = max(f[l][r], f[l][k]+f[k][r]+a[l]*a[k]*a[r]);
            }
        }
    }

    // for(int i=1;i<=2*n;i++)
    // {
    //     for(int j=1;j<=2*n;j++)
    //     {
    //         cout<<f[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    int res=0;
    for(int i=1;i<=n;i++)
        res = max(res,f[i][i+n]);
    cout<<res;
	return 0;
}