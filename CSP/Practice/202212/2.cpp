#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <sstream>
//#include <cmath>
//#include <bitset>
//#include <iomanip>
//#include <string>
#include <vector>
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
const int N = 111;
int n,m;
int cost[N];
int prv[N];

int early[N];
int late[N];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>prv[i];
    for(int i=1;i<=m;i++)
        cin>>cost[i], late[i]=n+1-cost[i];

    int mx=0;
    for(int i=1;i<=m;i++)
    {
        if(prv[i]==0)early[i]=1;
        else early[i] = early[prv[i]]+cost[prv[i]];
        mx = max(mx, early[i]+cost[i]);
        cout<<early[i]<<' ';
    }
    cout<<endl;
    if(mx<=n+1)
    {
        for(int i=m;i>0;i--)
        {
            if(prv[i])
            {
                late[prv[i]]=min(late[prv[i]],late[i]-cost[prv[i]]);
            }
        }
        for(int i=1;i<=m;i++)
            cout<<late[i]<<' ';
    }
	return 0;
}