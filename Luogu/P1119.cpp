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
//#include <map>
//#include <unordered_set>
//#include <unordered_map>
using namespace std;
#define LL long long
#define ULL unsigned long long
typedef pair<int,int> PII;
const int N = 205;


int n, m;
int T[N];
int ans[N];

int g[N][N];  // 存储每条边
int dist[N];  // 存储1号点到每个点的最短距离
// bool st[N];   // 存储每个点的最短路是否已经确定
// // 求1号点到n号点的最短路，如果不存在则返回-1
// int dijkstra()
// {
//     memset(dist, 0x3f, sizeof dist);
//     dist[1] = 0;
//     for (int i = 0; i < n - 1; i ++ )
//     {
//         int t = -1;     // 在还未确定最短路的点中，寻找距离最小的点
//         for (int j = 1; j <= n; j ++ )
//             if (!st[j] && (t == -1 || dist[t] > dist[j]))
//                 t = j;
//         // 用t更新其他点的距离
//         for (int j = 1; j <= n; j ++ )
//             dist[j] = min(dist[j], dist[t] + g[t][j]);
//         st[t] = true;
//     }
//     if (dist[n] == 0x3f3f3f3f) return -1;
//     return dist[n];
// }

int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>T[i];
    for(int i=0;i<m;i++)
    {
        int a,b,ww;
        cin>>a>>b>>ww;
        g[a][b] = g[b][a] = ww;
    }
	return 0;
}