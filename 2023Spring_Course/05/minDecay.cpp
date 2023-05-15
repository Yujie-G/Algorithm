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

int n;
PII a[10000];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i].second>>a[i].first;
    }
    sort(a,a+n);

    int cur = 0;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        cur+=a[i].second;
        if(cur>a[i].first)
            res= max(res, cur-a[i].first);
    }
    cout<<res;
	return 0;
}