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

const int N = 1e3;
string s;
int n;
int f[N][N];

int ans;
//][[]][]]
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s;
    n = s.length();
    for(int len=2;len<=n;len++)
    {
        for(int l=0;l+len-1<n;l++)
        {
            int r = l+len-1;
            if(s[l]=='[' && s[r]==']')
                f[l][r] = f[l+1][r-1]+2;
            for(int k=l;k<r;k++)
            {
                int tot=0;
                f[l][r] = max(f[l][r], f[l][k]+f[k][r]);
            }
            // if(s[l]=='[' && s[r]==']')
            //     f[l][r] = f[l+1][r-1]+2;
            // ans = max(ans, f[l][r]);
        }
    }

    cout<<f[0][n-1];
	return 0;
}