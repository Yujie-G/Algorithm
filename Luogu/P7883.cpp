#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long
const int N = 400010;

int n, tmp[N];
struct Point
{
    LL x, y;
} S[N];

bool cmp_x(const Point &a, const Point &b)
{
    return a.x < b.x || (a.x==b.x && a.y<b.y);
}
bool cmp_y(const Point &a, const Point &b) { return a.y < b.y; }

LL dist(int i, int j)
{
    return (S[i].x - S[j].x) * (S[i].x - S[j].x) + (S[i].y - S[j].y) * (S[i].y - S[j].y);
}

LL merge(int l, int r)
{
    LL d = 1e18;
    if (r-l<3)
    {
        for(int i=l;i<r;i++)
            for(int j=i+1;j<=r;j++)
                d = min(d, dist(i,j));
        sort(S+l,S+r+1,cmp_y);
        return d;
    }


    int mid = l + r >> 1;
    LL midx = S[mid].x;
    d = min(merge(l, mid), merge(mid + 1, r));
    inplace_merge(S+l,S+mid+1,S+r+1,cmp_y);

    int i, j, k = 0;
    for (i = l; i <= r; i++)
        if (abs(midx - S[i].x) < sqrt(d))
            tmp[k++] = i;

    for (i = 0; i < k; i++)
        for (j = i + 1; j < k && S[tmp[j]].y - S[tmp[i]].y < sqrt(d); j++)
        {
            LL d3 = dist(tmp[i], tmp[j]);
            if (d > d3)
                d = d3;
        }
    return d;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld %lld", &S[i].x, &S[i].y);
    sort(S, S + n, cmp_x);
    printf("%lld", merge(0, n - 1));
    return 0;
}