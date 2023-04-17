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

#define LL long long
#define ULL unsigned long long
using namespace std;
const int N = 17;
int K, q;

int tr[1 << N];
char tp[1 << N];

void update(int u, char c)
{
    if(!u)return;
    int c1=u<<1, c2 = c1+1;
    if(c=='?') tr[u] = tr[c1]+tr[c2];
    else if(c=='-')tr[u]=tr[c1];
    else tr[u] = tr[c2];
    tp[u]=c;
    update(u>>1,tp[u>>1]);
}

void build(string s, int i)
{
    int len = i, s_len = s.length();
    while (i<(1<<K))
    {
        for (int j = i+len-1; j >=i; j--)
        {
            tp[2*i+len-1-j] = s[s_len - j];
        }
        i<<=1;
        len=i;
    }
    for(int j=(1<<K);j<(1<<(K+1));j++)
    {
        tr[j] = 1;
    }
    for(int j=1<<(K-1);j<(1<<K);j++)
    {
        update(j,tp[j]);
    }
}

int convIdx(int i)
{
    int tmp = (1<<K)-i;
    int cnt=0,tt=tmp;
    while(tt)
    {
        cnt++;
        tt>>=1;
    }
    return (1<<(cnt-1))+(1<<cnt)-1-tmp;
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> K >> q;
    string s;
    cin >> s;
    build(s, 1);
    // for(int i=1;i<(1<<K);i++)
    // {
    //     cout<<tr[i]<<' ';
    // }
    // cout<<endl;
    // for(int i=1;i<(1<<K);i++)
    // {
    //     cout<<tp[i]<<' ';
    // }
    while (q--)
    {
        int i;
        char ch;
        cin >> i >> ch;
        update(convIdx(i), ch);
        cout << tr[1] << endl;
    }
    return 0;
}