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
#include <map>
//#include <unordered_set>
//#include <unordered_map>

#define LL long long
#define ULL unsigned long long
using namespace std;

string s;
string res;
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s;
    map<string,char>M;
    M["11"]='A';M["10"]='B';M["00"]='C';
    M["011"]='D';M["010"]='E';
    int i=0;
    string tmp="";
    for(i;i<s.length();i++)
    {
        tmp+=s[i];
        if(M.count(tmp))
        {
            res+=M[tmp];
            tmp="";
        }
    }
    cout<<res;
	return 0;
}