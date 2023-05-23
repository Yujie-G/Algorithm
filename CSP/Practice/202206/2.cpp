#include <iostream>
#include <unordered_set>


#define LL long long
#define ULL unsigned long long
using namespace std;
typedef pair<int,int> PII;
const int N = 1e3+11;
int n,L,s;

unordered_set<LL>M;
PII p[N];
int B[55][55];

int ans;

LL Hash(PII a)
{
    // std::cout<<"hash: "<<(1ll*a.first<<31) + a.second<<endl;
    return (1ll*a.first<<31) + a.second;
}
bool isok(PII point)
{
    int x=point.first, y=point.second;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            PII tmp = {x+i,y+j};
            if(x+i>L || y+j>L)
                return false;
            if((B[i][j] && !M.count(Hash(tmp))) ||
                (!B[i][j] && M.count(Hash(tmp))))
            return false;
        }
    }
    return true;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>L>>s;
    s++;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
        M.insert(Hash(p[i]));
    }
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            cin>>B[s-i-1][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(isok(p[i]))ans++;
    }
    cout<<ans;

	return 0;
}