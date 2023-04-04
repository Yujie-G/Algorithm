#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 5e4+10;

int n,k;
pair<int,int> rg[N];
int cnt;
void save(int l,int r)
{
    rg[cnt++]= {l,r};
}

queue<int>q;
int a[N];
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    sort(a,a+n);
    int l=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]-a[l]>k)
        {
            save(l,i-1);
            while(a[i]-a[l]>k)
            {
                l++;
            }
        }
    }
    if(l<n)save(l,n-1);
    // for(int i=0;i<cnt;i++)
    // {
    //     cout<<rg[i].first<<' '<<rg[i].second<<endl;
    // }
    int res=0;
    for(int i=0;i<cnt;i++)
    {
        int j=i+1;
        while(j<cnt)
        {
            int cur = rg[j].second-rg[i].first+1-max(0,rg[j].first-rg[i].second-1);
            res=max(res,cur);
            j++;
        }
    }

    cout<<res;
    return 0;
}