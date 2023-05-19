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

int n;
int x,y;


int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>x>>y;
    LL res=0;
    for(int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1>=0 && y1<=y && y2>0)
            res+=(min(x,x2)-x1)*(min(y,y2)-max(0,y1));
        else if(x1<0 && y1<y && x2>0)
            res+=(min(y2,y)-max(y2,0))*min(x2,x);
    }
    cout<<res;
	return 0;
}