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
int n,m;

int st[10][10];
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='_')st[i][j] = -1;
            else st[i][j] = ch-'0';
        }
    }

    for(int i=0;i<n;i++)
    {
        int flg=1;
        for(int j=0;j<(1<<m) && flg;j++)
        {
            int s=j;
            int idx=0;
            while(s){
                if(s&1)
                {
                    if(i>0)
                    {
                        st[i-1][m-1-idx]--;

                        if(idx>0)
                        {

                        }
                        if(idx<m-1)
                        {

                        }
                    }
                    if(i<n-1)
                    {
                        if(idx>0)
                        {

                        }
                        if(idx<m-1)
                        {
                            
                        }
                    }
                }
                idx++;
                s>>=1;
            }
        }
    }
	return 0;
}