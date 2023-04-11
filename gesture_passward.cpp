
#include <iostream>

#define LL long long
#define ULL unsigned long long
using namespace std;

const int N = 1000;
int h[N],e[N],ne[N],idx=1;
bool st[N];

int a[N][2]={
{1,2},{1,4},{1,5},{1,6},{1,8},
{2,1},{2,3},{2,4},{2,5},{2,6},{2,7},{2,9},
{3,2},{3,4},{3,5},{3,6},{3,8},
{4,1},{4,2},{4,3},{4,5},{4,7},{4,8},{4,9},
{5,1},{5,2},{5,3},{5,4},{5,6},{5,7},{5,8},{5,9},
{6,1},{6,2},{6,3},{6,5},{6,7},{6,8},{6,9},
{7,2},{7,4},{7,5},{7,6},{7,8},
{8,1},{8,3},{8,4},{8,5},{8,6},{8,7},{8,9},
{9,2},{9,4},{9,5},{9,6},{9,8}};

int c[][3]={// start, end, mid
{1,3,2},{1,7,4},{1,9,5},
{2,8,5},
{3,1,2},{3,7,5},{3,9,6},
{4,6,5},
{6,4,5},
{7,1,4},{7,3,5},{7,9,8},
{8,2,5},
{9,1,5},{9,3,6},{9,7,8}
};
void add(int a,int b)
{
	e[idx] = b, ne[idx]=h[a], h[a]=idx++;
}
LL res;
void dfs(int u)
{
	for(int i=h[u];i;i=ne[i]){
		int j=e[i];
		if(!st[j])
		{
			res++;
			st[j]=1;
			dfs(j);
			st[j]=0;
		}
	}
	for(int i=0;i<16;i++)
	{
		int s=c[i][0],ed=c[i][1],md=c[i][2];
		if(s==u && st[md] && !st[ed]){
			res++;
			st[ed]=1;
			dfs(ed);
			st[ed]=0;
		}
	}
}
int main()
{
	for(int i=0;i<N;i++)
		add(a[i][0],a[i][1]);
	for(int i=1;i<=9;i++)
		st[i]=1, dfs(i), st[i]=0;
	cout<<res<<endl;
	return 0;
}