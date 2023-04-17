#include <iostream>
#include <algorithm>

using namespace std;

int a[200000];
// k belongs to [0,n-1]
int n,k;

void qsort(int a[], int l, int r)
{
	int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (a[i] < x);
        do j -- ; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
	//快排后数组被划分为三块： l<=j<=i<=r, i==j || i==j+1
	if (k <= j) qsort(a, l, j);//在左区间只需要搜左区间
	else if (j+1 < k) qsort(a, j+1, r);//在右区间只需要搜右区间
	else //如果刚好即为分界点则直接输出
	{
		printf("%d", a[j + 1]);
		return;
	}
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    qsort(a, 0,n-1);
    return 0;
}
