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
const int N = 10000;

int a[N];
int n;

int res;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    while(cin>>a[n])n++;
    int l=0, r=n-1;

    while(l<r)
    {
        int tmp = (r-l)*min(a[l],a[r]);
        res = max(res, tmp);
        if(a[l]<a[r])l++;
        else r--;
    }
    cout<<res;
	return 0;
}