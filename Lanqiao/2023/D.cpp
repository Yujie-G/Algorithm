#include <iostream>
#include <cstring>
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
const int N = 5010;
char s[N];

int nxt[N];
int pre[N];
LL res;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s;
    int n = strlen(s);
    for(int i=0;i<n;i++)
    {
        int pv = s[i], idx = i;
        while(pv==s[i])i++;
        if(i>idx) i--;
        for(int j=idx;j<=i;j++)
        {
            nxt[j] = i;
            pre[j] = idx;
        }
    }
    // for(int i=0;i<n;i++)cout<<nxt[i]<<' ';
    // cout<<endl;
    // for(int i=0;i<n;i++)cout<<pre[i]<<' ';
    // cout<<endl;
    for(int len=2;len<=n;len++)
    {
        for(int l=0;l+len<=n;l++)
        {
            int r = l+len-1;
            int i=l,j=r;
            while(i<j)
            {
                if(s[i]>s[j])
                {
                    res++;
                    break;
                }
                else if(s[i]==s[j])
                {
                    i=nxt[i];
                    j=pre[j];
                    i++;
                    j--;
                }
                else break;
            }
        }
    }
    cout<<res;
	return 0;
}