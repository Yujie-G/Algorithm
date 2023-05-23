#include <iostream>
#include <cmath>

using namespace std;


const double pai = acos(-1);
int len;
int a[8][8];
int scan_arr[64];
int scan_mat[8][8];
int a_mul_scan[8][8];
double trans[8][8];
int ans[8][8];

void output(const int m[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << m[i][j] << " "[j==7?1:0];
        cout << endl;
    }
}

void output(const double m[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << m[i][j] << ' ';
        cout << endl;
    }
}

void discrete_cos(const int a[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            double tmp = .0;
            for (int u = 0; u < 8; u++)
            {
                for (int v = 0; v < 8; v++)
                {
                    double flg = 1.0;
                    if (!u)
                        flg *= sqrt(0.5);
                    if (!v)
                        flg *= sqrt(0.5);
                    tmp += flg * a[u][v] * cos((i + 0.5) * pai * u / 8) * cos((j + 0.5) * pai * v / 8);
                }
            }
            trans[i][j] = tmp * 0.25;
        }
    }
}

void element_mul(const int a[8][8], const int b[8][8], int c[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            c[i][j] = a[i][j] * b[i][j];
        }
    }
}

void work()
{
    int t = 0;
    int i = 0, j = 0;
    int dir = 0; // 0:right-up, 1:left-down
    while (t < len)
    {
        scan_mat[i][j] = scan_arr[t];
        if (dir)
            i++, j--;
        else
            i--, j++;
        if (i < 0 || i >= 8)
        {
            if(i<0)
            {
                i=0;
            }
            else if(i>=8)
            {
                i=7;
                j+=2;
            }
            dir = ~dir;
        }
        else if (j < 0 || j >= 8)
        {
            if(j<0)
            {
                j=0;
            }
            else if(j>=8)
            {
                j=7;
                i+=2;
            }
            dir = ~dir;
        }
        t++;
    }

    element_mul(scan_mat, a, a_mul_scan);
    discrete_cos(a_mul_scan);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            ans[i][j] = round(trans[i][j] + 128.0);
            ans[i][j] = max(ans[i][j], 0);
            ans[i][j] = min(ans[i][j], 255);
        }
    }
    // cout<<"SCAN:"<<endl;
    // output(scan_mat);
    // cout<<"MUL:"<<endl;
    // output(a_mul_scan);
    // cout<<"TRANS:"<<endl;
    // output(trans);
    // cout<<"ans:"<<endl;
    // output(ans);
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> a[i][j];
    cin >> len;
    int flg;
    cin >> flg;
    for (int i = 0; i < len; i++)
        cin >> scan_arr[i];
    work();
    if (flg == 0)
        output(scan_mat);
    else if (flg == 1)
        output(a_mul_scan);
    else if (flg == 2)
        output(ans);
    return 0;
}