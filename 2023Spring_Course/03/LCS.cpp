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

int f[1000][1000];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    int m=s1.length(),n = s2.length();
    // cout<<m<<endl<<n<<endl;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if(s1[i-1]==s2[j-1])
                f[i][j]=max(f[i-1][j-1]+1,f[i][j]);
        }

    cout<<f[m][n];
	return 0;
}