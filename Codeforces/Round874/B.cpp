#include <iostream>
//#include <cstring>
#include <algorithm>
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
const int N = 1e5+11;
PII a[N];
int b[N];
int ans[N];
bool cmp1(PII a1, PII a2)
{
    return a1.first<a2.first;
}
bool cmp2(PII a1, PII a2)
{
    return a1.second<a2.second;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int q;cin>>q;
    while(q--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            int tmp;cin>>tmp;
            a[i]={i,tmp};
        }
        for(int i=0;i<n;i++)
            cin>>b[i];
        sort(b,b+n);
        sort(a,a+n,cmp2);
        for(int i=n-1;i>=0;i--)
        {
            ans[a[i].first]=b[i];
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
	return 0;
}