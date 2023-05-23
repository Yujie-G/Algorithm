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
const int N = 3e5+11;
int n;
int a[N];
int e[N],h[N],ne[N],idx=1;
void add(int a, int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

LL f[N];
int nst[N];
void dp(int u)
{
    LL &res = f[u];
    for(int i=h[u];i;i=ne[i])
    {
        dp(e[i]);
        res+=f[e[i]];
    }
    if(!res)return;
    
}

//merge sort!
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int p;cin>>p;
        add(p,i);
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];

    dp(1);
	return 0;
}