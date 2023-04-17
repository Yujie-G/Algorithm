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
const int N = 15;
int n;
int a[N],b[N];

bool st[N];
LL res;
void dfs(int u)
{
    if(u==n){
        res++;
        return;
    }
    for(int i=0;i<n;i++){
        if(!st[i] && b[i]>a[u])
        {
            st[i]=1;
            dfs(u+1);
            st[i]=0;
        }
    }
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    dfs(0);
    cout<<res;
	return 0;
}