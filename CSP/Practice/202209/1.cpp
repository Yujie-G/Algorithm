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
const int N = 22;
LL c[N];
int a[N];
int n;
LL m;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    c[0]=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        c[i] = c[i-1]*a[i];
    }
    LL res=0;
    for(int i=1;i<=n;i++)
    {
        LL s = m%c[i];
        cout<< (s-res)/c[i-1]<<' ';
        res=s;
    }
	return 0;
}