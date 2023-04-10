#include <iostream>

using namespace std;
int q[100000];
int n;
void quick_sort(int q[], int l, int r)
{
    if (l > r) return;
    int i = l+1, j = r;
    cout<<q[l]<<endl;
    while (i < j)
    {
        while (i<=r && q[i] <= q[l])i++;
        while (j>l && q[j] >= q[l]) j--;
        if(i<j) swap(q[i], q[j]);
    }
    if(i>j  || q[i]>q[l]) swap(q[i-1],q[l]);
    else swap(q[i],q[l]),i++;
    quick_sort(q, l, i-2);
    quick_sort(q, i, r);
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    quick_sort(q,0,n-1);
    for(int i=0;i<n;i++)
    cout<<q[i]<<' ';
    return 0;
}