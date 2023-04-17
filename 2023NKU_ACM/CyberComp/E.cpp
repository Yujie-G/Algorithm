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
#include <map>
//#include <unordered_set>
//#include <unordered_map>

#define LL long long
#define ULL unsigned long long
using namespace std;

const int N = 2e5+10;

int n,q;
int S[N];
map<int,int> M[N];

void merge(int i,int j)
{
    for(auto it:M[j])
    {
        M[i][it.first]+=it.second;
    }
}
int Find(int u)
{
    if(S[u]<0)return u;
    return S[u] = Find(S[u]);
}

void Disj(int a,int b)
{
    int r1=Find(a), r2=Find(b);
    if(r1==r2)return;
    if(S[r1]<S[r2])
    {
        S[r1]+=S[r2];
        S[r2] = r1;
        merge(r1,r2);
    }
    else{
        S[r2]+=S[r1];
        S[r1] = r2;
        merge(r2,r1);
    }
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    memset(S,-1,sizeof S);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        int t;cin>>t;
        M[i].insert({t,1});
    }
    while(q--)
    {
        int type,a,b;
        cin>>type>>a>>b;
        if(type)
        {
            Disj(a,b);
        }
        else{
            cout<<M[Find(a)][b]<<endl;
        }
    }
	return 0;
}