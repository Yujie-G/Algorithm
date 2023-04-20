#include <iostream>
#include <cstring>
#include <algorithm>
// #include <sstream>
#include <cmath>
// #include <bitset>
// #include <iomanip>
// #include <string>

#include <vector>
// #include <list>
// #include <queue>
// #include <stack>
// #include <set>
// #include <map>
// #include <unordered_set>
// #include <unordered_map>
using namespace std;
#define LL long long
#define ULL unsigned long long
typedef pair<int, int> PII;
const int N = 1e3 + 10;

pair<double, PII> edges[N * N];
PII nodes[N];
int n, k, m;
int S[N];
int cur;

bool cmp(const pair<double, PII> &e1, const pair<double, PII> &e2)
{
    return e1.first < e2.first;
}
double dist(const PII &n1, const PII &n2)
{
    return sqrt((n1.first - n2.first) * (n1.first - n2.first) + (n1.second - n2.second) * (n1.second - n2.second)) + .0;
}
int Find(int u)
{
    if (S[u] < 0)
        return u;
    return S[u] = Find(S[u]);
}

bool disj(int a, int b)
{
    int rt1 = Find(a), rt2 = Find(b);
    if (rt1 == rt2)
        return false;
    // cout<<"disj: "<<a<<" "<<b<<endl;
    S[rt1] += S[rt2];
    S[rt2] = rt1;
    cur--;
    return true;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    memset(S,-1,sizeof S);
    cin >> n >> k;
    cur = n;
    for (int i = 0; i < n; i++)
    {
        int x,y;cin>>x>>y;
        nodes[i]={x,y};
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            edges[m++] = {dist(nodes[i], nodes[j]), {i, j}};
        }
    }
    sort(edges, edges + m, cmp);
    // for(int i=0;i<m;i++)
    // {
    //     cout<<edges[i].first<<endl;
    // }
    int i = 0;
    while (cur > k)
    {
        disj(edges[i].second.first, edges[i].second.second);
        i++;
    }
    while(i<m && !disj(edges[i].second.first, edges[i].second.second)) i++;
    printf("%.2f",edges[i].first);
    return 0;
}