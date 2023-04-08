#include <iostream>
//#include <cstring>
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
typedef pair<int,int> PII;
#define LL long long
#define ULL unsigned long long


int count(int n)
{
    int cnt=0;
    while(n)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}

bool isok(int n){
    int c = count(n);
    if(c&1)return false;
    int s1=0,s2=0;
    for(int i=0;i<c/2;i++)
    {
        s1+=n%10;
        n/=10;
    }
    for(int i=0;i<c/2;i++)
    {
        s2+=n%10;
        n/=10;
    }
    return s1==s2;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int res=0;
    for(int i=1;i<100000000;i++)
    {
        if(isok(i))res++;
    }
    cout<<res;
	return 0;
}