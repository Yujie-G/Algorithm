#include <iostream>
#include <cstring>
// #include <algorithm>
// #include <sstream>
// #include <cmath>
// #include <bitset>
// #include <iomanip>
// #include <string>

// #include <vector>
// #include <list>
#include <queue>
// #include <stack>
// #include <set>
// #include <map>
// #include <unordered_set>
// #include <unordered_map>
using namespace std;
#define LL long long
#define ULL unsigned long long
typedef pair<int, int> PII;
const int N = 2e6+10, mod = 100003;

int n, m;                             // 点的数量
int h[N], e[N], ne[N], idx = 1; // 邻接表存储所有边

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
LL cnt[N];
int dist[N]; // 存储所有点到1号点的距离
bool st[N];  // 存储每个点的最短距离是否已确定

void bfs()
{
    queue<int> q;
    q.push(1);
    st[1]=1;
    cnt[1]=1;
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(int i=h[t];i;i=ne[i])
        {
            int j=e[i];
            if(!st[j])
            {
                st[j]=1;
                cnt[j]=cnt[t];
                dist[j]=dist[t]+1;
                q.push(j);
            }
            else if(dist[j] == dist[t]+1)
                cnt[j]+=cnt[t];
            cnt[j] %= mod;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y),add(y,x);
    }
    bfs();
    for (int i = 1; i <= n; i++)
        cout << cnt[i] << endl;
    return 0;
}