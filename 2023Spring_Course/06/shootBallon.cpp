#include <iostream>
//#include <cstring>
#include <algorithm>
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
const int N = 1000;
PII a[N];
int n;

bool cmp(PII a,PII b)
{
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    int ans=0;
    int pv=-1000000;
    for(int i=0;i<n;i++)
    {
        if(a[i].first<=pv) continue;
        ans++;
        pv=a[i].second;
    }
    cout<<ans<<endl;
	return 0;
}