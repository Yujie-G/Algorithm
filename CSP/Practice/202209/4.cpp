#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include <unordered_map>
using namespace std;
#define LL long long
#define ULL unsigned long long
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

const int M = 1e5 + 11;

int n, m, q;
int cnt[M];
int mx;
int m_idx;

unordered_map<int, LL> map; // M[i] : idx of work_i

set<PIII> segs;

bool cmp_l(const PIII &a, const PIII &b)
{
    return a.first.first < b.first.first;
}

bool cmp_r(const PIII &a, const PIII &b)
{
    return a.first.second < b.first.second;
}

void update(int x, int len)
{
    cnt[map[x]] += len;
    // if (cnt[map[x]] >= mx && x != 0)
    // {
    //     mx = cnt[map[x]];
    //     // if(cnt[map[x]]==mx)
    //     //     m_idx = min(m_idx,x);
    //     // else
    //     m_idx = x;
    // }
}

void insert(int l, int r, int x)
{
    PIII cur = {{l, r}, x};
    if (segs.empty())
    {
        update(x, r - l + 1);
        segs.insert(cur);
        return;
    }

    auto ll = upper_bound(segs.begin(), segs.end(), cur, cmp_l);
    ll--;

    auto seg = *ll;
    if (l > seg.first.first)
    {
        update(seg.second, l - seg.first.first);
        segs.insert({{seg.first.first, l - 1}, seg.second});
    }

    auto rr = lower_bound(segs.begin(), segs.end(), cur, cmp_r);
    seg = *rr;
    if (r < seg.first.second)
    {
        update(seg.second, seg.first.second - r);
        segs.insert({{r + 1, seg.first.second}, seg.second});
    }

    while (ll != rr)
    {
        auto pre = ll;
        ll++;
        seg = *pre;
        update(seg.second, -(seg.first.second - seg.first.first + 1));
        segs.erase(pre);
    }
    update((*ll).second, -((*ll).first.second - (*ll).first.first + 1));
    segs.erase(ll);
    update(x, r - l + 1);
    segs.insert(cur);
}

void test()
{
    cout << "segs:" << endl;
    for (auto i : segs)
    {
        cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
    }

    for (int i = 0; i <= m; i++)
    {
        cout << "i: " << i << " " << cnt[map[i]] << endl;
    }
    cout << "-------" << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 0; i <= m; i++)
        map[i] = i;
    insert(1, n, 0);
    while (q--)
    {
        int flg;
        cin >> flg;
        if (flg == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            insert(l, r, x);
            // test();
        }
        else if (flg == 2)
        {
            int x, w;
            cin >> x >> w;
            cnt[map[w]] += cnt[map[x]];
            cnt[map[x]] = 0;
            auto it = segs.begin();
            while (it != segs.end())
            {
                auto ss = *it;
                if (ss.second == x)
                {
                    auto seg = it;
                    segs.insert({ss.first, w});
                    it++;
                    segs.erase(seg);
                }
                else
                    it++;
            }
        }
        else if (flg == 3)
        {
            int x, y;
            cin >> x >> y;
            swap(map[x], map[y]);
        }
        else if (flg == 4)
        {
            int w;
            cin >> w;
            cout << cnt[map[w]] << endl;
        }
        else if (flg == 5)
        {
            int mx = 0, idx = 0;
            for (int i = 1; i <= m; i++)
            {
                if (cnt[map[i]] > mx)
                {
                    mx = cnt[map[i]];
                    idx = i;
                }
            }
            cout << idx << endl;
        }
    }

    return 0;
}