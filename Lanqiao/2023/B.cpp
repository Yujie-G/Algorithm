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

LL cnt;
LL dfs(int u,int k)
{
    if(k>9)return 0;
    if(!u)
    {
        if(k==7)
            return 1;
        else return 0;
    }
    LL tmp=0;
    tmp += dfs(u-1, 0);
    tmp += dfs(u-1, k+1);
    return tmp;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i=0;i<=30;i++)
    {
        cnt+=dfs(i,0);
    }
    cout<<cnt;
	return 0;
}