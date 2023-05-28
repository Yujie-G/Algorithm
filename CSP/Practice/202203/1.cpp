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
#include <unordered_set>
//#include <unordered_map>
using namespace std;
#define LL long long
#define ULL unsigned long long
typedef pair<int,int> PII;

int res;

int n;
int k;
unordered_set<int> S;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    S.insert(0);
    while(k--)
    {
        int a,b;
        cin>>a>>b;
        if(!S.count(b))res++;
        S.insert(a);
    }

    cout<<res;
	return 0;
}