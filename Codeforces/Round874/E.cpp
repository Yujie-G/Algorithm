// #include <iostream>
// #include <cstring>
// //#include <algorithm>
// //#include <sstream>
// //#include <cmath>
// //#include <bitset>
// //#include <iomanip>
// //#include <string>

// //#include <vector>
// //#include <list>
// //#include <queue>
// //#include <stack>
// //#include <set>
// //#include <map>
// //#include <unordered_set>
// //#include <unordered_map>
// using namespace std;
// #define LL long long
// #define ULL unsigned long long
// typedef pair<int,int> PII;

// const int N = 2e5+11;
// int S[N];
// int ff[N];

// int Find(int u)
// {
//     if(S[u]<0)return u;
//     return S[u] = Find(S[u]);
// }

// void disj(int a, int b)
// {
//     if(a>b){
//         disj(b,a);
//         return;
//     }
//     ff[a]++,ff[b]++;
//     int r1= Find(a), r2 = Find(b);
//     if(ff[a]==3 || ff[b]==3)
//         S[r1]=-2;
//     if(r1==r2)
//     {
//         // if(r1!=a || S[r1]==-2)
//         //     ff[r1]=1;
//         return;
//     }
//     // S[r1]+=S[r2];
//     S[r2]=r1;
// }

// int main()
// {
// 	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//     int q;cin>>q;
//     while(q--)
//     {
//         memset(S,-1,sizeof(S));
//         memset(ff,0 ,sizeof ff);
//         int n;cin>>n;
//         for(int i=1;i<=n;i++)
//         {
//             int c;cin>>c;
//             disj(i,c);
//         }
//         int cnt1=0, cnt2=0;
//         for(int i=1;i<=n;i++)
//         {
//             if(S[i]<0)cnt1++;
//             if(S[i]==-2)cnt2++;
//         }
//         cout<<min(cnt1-cnt2+1,cnt1);
//         cout<<' '<<cnt1<<endl;
//     }
// 	return 0;
// }