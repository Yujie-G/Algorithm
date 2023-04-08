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

#define LL long long
#define ULL unsigned long long
using namespace std;

// 4n & 2n+1
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int l,r;
	cin>>l>>r;
	int s1 = (r+1>>1)-(l>>1);
	int s2 = (r>>2) - (l-1>>2);
	// cout<<s1<<endl<<s2<<endl;
	cout<<s1+s2;
	return 0;
}