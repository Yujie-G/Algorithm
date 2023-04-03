// robot gender

#include <iostream>
//#include <cstring>
#include <algorithm>
//#include <sstream>
#include <cmath>
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

#define LL long long
#define ULL unsigned long long
using namespace std;

string sub(string s,int a)
{
    int i=0,t=0;
    while(a)
    {
        t = s[i]-'0' - t - a%10;
        s[i] = ((t + 10) % 10)+'0';
        if (t < 0) t = 1;
        else t = 0;
        a/=10;
        i++;
    }
    if(t)s[i]-=t;
    return s;
}
string div(string s,int b)
{
    string c;
    int r=0;
    for (int i = s.size() - 1; i >= 0; i -- )
    {
        r = r * 10 + s[i]-'0';
        c.push_back(r / b + '0');
        r %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == '0') c.pop_back();
    return c;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;string s;
    cin>>n>>s;
    reverse(s.begin(),s.end());
    s = sub(s,n+1);
    cout<<s<<endl;
    s = div(s,pow(2,n+1)-1);
    int i=0;
    s[i]++;
    while(s[i]-'0'==10)
    {
        s[i]='0';
        i++;
        s[i]++;
    }
    reverse(s.begin(),s.end());
    cout<<s;
	return 0;
}