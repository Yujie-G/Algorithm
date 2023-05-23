#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <sstream>
#include <cmath>
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

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;double m;
    cin>>n>>m;
    m+=1.0;
    double res=.0;
    for(int i=0;i<=n;i++)
    {
        double tt;cin>>tt;
        res+=tt*pow(m,n-i);
    }

    cout<<res/pow(m,n);
	return 0;
}