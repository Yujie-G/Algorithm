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
#include <set>
//#include <map>
#include <unordered_set>
//#include <unordered_map>
using namespace std;
#define LL long long
#define ULL unsigned long long
typedef pair<int,int> PII;

unordered_set<string> S;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int q;cin>>q;
    while(q--)
    {
        int n;string s;
        cin>>n>>s;
        for(int i=0;i<n-1;i++)
        {
            string tmp = s.substr(i,2);
            if(S.count(tmp))continue;
            S.insert(tmp);
        }
        cout<<S.size()<<endl;
        S.clear();
    }

	return 0;
}