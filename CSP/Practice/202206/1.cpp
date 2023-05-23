#include <iostream>
//#include <cstring>
//#include <algorithm>
//#include <sstream>
#include <cmath>
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
double a[1010];

double mean;
double d;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        mean+=a[i];
    }
    mean/=n;
    for(int i=0;i<n;i++)
    {
        d+=(a[i]-mean)*(a[i]-mean);
    }
    d/=n;
    d = sqrt(d);

    // cout<<mean<<endl<<d<<endl<<"---------"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<(a[i]-mean)/d<<endl;
    }
	return 0;
}