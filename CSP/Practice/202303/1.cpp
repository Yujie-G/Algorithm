#include <iostream>
using namespace std;
#define LL long long
#define ULL unsigned long long

int n;
int x,y;


int main()
{
    cin>>n>>x>>y;
    LL res=0;
    for(int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1>=0 && x1<x && y1<y && y2>0)
            res+=(min(x,x2)-x1)*(min(y,y2)-max(0,y1));
        if(x1<0 && y1<y && x2>0 && y2>0)
            res+=(min(y2,y)-max(y1,0))*min(x2,x);
    }
    cout<<res;
	return 0;
}