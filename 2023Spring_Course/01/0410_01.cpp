#include <iostream>
#include <iomanip>
using namespace std;

double qpow(double a, int b)
{
    double res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    double n;
    int k;
    cin>>n>>k;
    cout<<fixed<<setprecision(2)<<qpow(n,k);
    return 0;
}