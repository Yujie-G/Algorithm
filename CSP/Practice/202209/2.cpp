#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int n, x;
int a[33];

set<int> S;

int tmp[1000000];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    int res = 3e6;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        // cout<<"S:  ";
        for (auto j : S)
        {
            // cout<<j<<' ';
            tmp[cnt++] = j + a[i];
        }
        // cout<<endl;
        if (a[i] < x)
            S.insert(a[i]);
        else
        {
            res = min(res, a[i]);
            break;
        }
        for (int j = 0; j < cnt; j++)
        {
            if(tmp[j]>=x)
            {
                res=min(res,tmp[j]);
                break;
            }
            if (!S.count(tmp[j]))
                S.insert(tmp[j]);
        }
    }
    cout << res;
    return 0;
}