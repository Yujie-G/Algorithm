#include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <sstream>
// #include <cmath>
// #include <bitset>
// #include <iomanip>
// #include <string>

// #include <vector>
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

const int N = 2e5 + 11;
int a[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        int mn = 1e9, idx=-1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if(a[i]<mn)
            {
                mn = a[i];
                idx=i;
            }
        }
        int flg = a[idx] & 1;

        bool stat = true;
        for (int i = 0; i < n; i++)
        {
            if(i==idx)continue;
            int cflg = a[i] & 1;
            if(cflg==flg) continue;
            if(cflg==0 && flg==1 && a[i]>mn)
                continue;
            else{
                stat = false;
                break;
            }

        }

        if(stat)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}