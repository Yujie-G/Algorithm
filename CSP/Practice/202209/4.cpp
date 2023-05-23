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
typedef pair<PII,int> PIII;

const int M = 1e5+11;

int n,m,q;
int cnt[M];
int mx;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m>>q;
    while(q--)
    {
        int flg;cin>>flg;
        if(flg==1)
        {

        }
        else if(flg==2)
        {
            
        }
        else if(flg==3)
        {
            
        }
        else if(flg==4)
        {
            int w;cin>>w;
            cout<<cnt[w]<<endl;
        }
        else if(flg==5)
        {
            cout<<mx<<endl;
        }
    }
	return 0;
}