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
int a[2010];
int t[2010];
int n;
int compare(int m, int q[], int r[])
{
    for(int i=0;i<m;i++)
        if(q[i]==r[i])continue;
        else{
            if(q[i]<r[i])
                return -1;
            if(q[i]>r[i])
                return 1;
        }
    return 0;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int q;cin>>q;
    while(q--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int l=0;l<n;l++)
        {
            for(int r=l;r<n;r++)
            {
                int l1=l,l2=n-r-1;
                int t_l = max(l1,l2);
                int flg = compare(t_l,a,a+n-t_l);
            }
        }
    }
	return 0;
}