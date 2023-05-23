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

const int N = 2520;
const int M = 510;

int n;
int a[N][M];
int dn[N];

void work(string s)
{

}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int id;cin>>id;
        dn[i]=id;
        int m;cin>>m;
        for(int j=0;j<m;j++)
        {
            int idx,val;cin>>idx>>val;
            a[i][idx]=val;
        }
    }

    int q;cin>>q;
    while(q--)
    {
        string s;
        work(s);
        cout<<endl;
    }
	return 0;
}