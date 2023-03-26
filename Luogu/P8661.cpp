#include <iostream>
//#include <cstring>
#include <algorithm>
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

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 1e5+10;
int id[N];
int n,d,k;
pair<int,int> ti[N];
vector<int> ans;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>d>>k;
    for(int i=0;i<n;i++)
    {
        cin>>ti[i].first>>ti[i].second;
    }
    sort(ti,ti+n);
    int tt=0,hh=0;
    while(tt<n)
    {
        while(tt<n && ti[tt].first-ti[hh].first<d)
        {
            id[ti[tt].second]++;
            if(id[ti[tt].second]>=k)ans.push_back(ti[tt].second);
            tt++;
        }
        id[ti[hh].second]--;
        hh++;
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(auto i:ans)cout<<i<<endl;
	return 0;
}