#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10010, MOD = 1e9 + 7;

int n;
int a[N];
int f[N];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    f[0] = 1;
    for (int i = 1; i <= n; i ++ ) 
    {
        int Min = n + 1, Max = 0;
        for (int j = i; j; j -- )
        {
            Min = min(Min, a[j]), Max = max(Max, a[j]);
            if (i - j == Max - Min)
                f[i] = (f[i] + f[j - 1]) % MOD;
        }
    }

    cout << f[n] << endl;

    return 0;
}