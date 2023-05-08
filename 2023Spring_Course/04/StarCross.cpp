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
using namespace std;
#define LL long long
#define ULL unsigned long long
typedef pair<int,int> PII;
const int N = 1e5;
int n;
int a[N];

LL f[N];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    memset(f,0x3f,sizeof f);
    f[0]=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<=min(i+a[i],n);j++)
            f[j]=min(f[j], f[i]+1);
    cout<<f[n];
	return 0;
}