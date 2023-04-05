#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n, m, u, v, ans, cnt[1010], sum;
bool bj[1010], a[1010][1010];
void dfs(LL now)
{
    if (now == v)
    {          // 如果走到终点了，
        sum++; // 路径总数加一。
        for (int i = 1; i <= n; i++)
            if (bj[i] == 1)
                cnt[i]++; // 每个被走过的点，被走总次数加一
    }
    else
    {
        for (int i = 1; i <= n; i++)
            if (a[now][i] == 1 && bj[i] == 0)
            {              // 如果两点连通且下一步要走到的点未被走过，
                bj[i] = 1; // 标记。
                dfs(i);
                bj[i] = 0; // 回溯一步。
            }
    }
}
int main()
{
    scanf("%lld%lld", &n, &m);
    while (m--)
    {
        scanf("%lld%lld", &u, &v);
        a[u][v] = a[v][u] = 1; // 输入邻接矩阵。因为是无向的，所以u到v和v到u都要设为1。
    }
    scanf("%lld%lld", &u, &v);
    dfs(u);
    if (sum > 0)
    { // dfs求解
        for (int i = 1; i <= n; i++)
            if (cnt[i] == sum)
                ans++;           // 如果这个点被走过的总次数与路径总数相等，那么删去这个点起点与终点间一定不连通。
        printf("%lld", ans - 1); // 因为起点也被算在内，所以总危险系数要减去起点的1。
    }
    else
        printf("-1"); // 如果询问的两点无路径连通则输出'-1'。
    return 0;
}
