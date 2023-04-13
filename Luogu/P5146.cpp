#include <iostream>
#include <cstring>
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

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 1000010;
int n;
LL f[N];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    memset(f,-0x3f,sizeof f);
    cin>>n;
    LL mn;
    for(int i=1;i<=n;i++)
    {
        LL a;cin>>a;
        if(i==1)
        {
            mn=a;
            continue;
        }
        f[i]=max(f[i-1], a-mn);
        mn=min(mn,a);
    }
    cout<<f[n];
	return 0;
}