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

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 1e5+10;
int n;
int a[N];
int s[N];
LL res;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i] = s[i-1]^a[i];
    }
    for(int len=1;len<=n;len++)
    {
        for(int l=1;l+len<=n+1;l++)
        {
            int r = l+len-1;
            // cout<<len<<' '<<l<<' '<<r<<endl;
            res+=s[r]^s[l-1];
        }
    }
    cout<<res;
	return 0;
}