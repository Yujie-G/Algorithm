#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1000001;
int n, tmp[N];
struct Point
{
    double x, y;
} S[N];

bool cmp_x(const Point &a, const Point &b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool cmp_y(const Point &a, const Point &b) { return a.y < b.y; }

double dist(int i, int j)
{
    return sqrt((S[i].x - S[j].x) * (S[i].x - S[j].x) + (S[i].y - S[j].y) * (S[i].y - S[j].y)+.0);
}

double merge(int l, int r)
{
    double d = 1e16;
    if (r-l<3)
    {
        for(int i=l;i<r;i++)
            for(int j=i+1;j<=r;j++)
                d = min(d, dist(i,j));
        sort(S+l,S+r+1,cmp_y);
        return d;
    }

    int mid = l + r >> 1;
    //midx一定要在分治前面求，否则分治结束后会改变点在数组中的位置
    double midx = S[mid].x;

    d = min(merge(l, mid), merge(mid + 1, r));
    inplace_merge(S+l,S+mid+1,S+r+1,cmp_y);

    int k = 0;
    for (int i = l; i <= r; i++)
        if (fabs(midx - S[i].x) < d)
            tmp[k++] = i;

    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k && S[tmp[j]].y - S[tmp[i]].y < d; j++)
        {
            double d3 = dist(tmp[i], tmp[j]);
            if (d > d3)
                d = d3;
        }
    return d;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf%lf", &S[i].x, &S[i].y);
    sort(S, S + n, cmp_x);
    printf("%.4lf\n", merge(0, n - 1));
    return 0;
}