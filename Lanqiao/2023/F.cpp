#include <iostream>
//#include <cstring>
//#include <algorithm>
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
#include <map>
#include <unordered_set>
//#include <unordered_map>

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 32;
int n,m;
typedef pair<double,int> PDI;
map<double,int> M;


int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        double a;
        cin>>a;
        vector<PDI>v;
        v.push_back({a*0.5, 1});
        v.push_back({a,0});
        for(auto j:M)
        {
            double k = j.first;
            int val = j.second;
            v.push_back({k+a,val});
            v.push_back({k+a/2,val+1});
        }
        for(auto j:v)
        {
            double k = j.first;
            int val = j.second;
            // cout<<"v: key:"<<k<<" val:"<<val<<endl;
            if(M.count(k)) M[k] = min(M[k], val);
            else M[k]=val;
        }
    }
    if(M.count((double)m))cout<<M[(double)m];
    else cout<<-1;
	return 0;
}