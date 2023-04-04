#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int a[maxn], b[maxn];

//自定义排序函数
bool cmp(int x, int y)
{
    return b[x] < b[y] || b[x] == b[y] && x < y;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        //求i的数位之和
        int num = i;
        while(num)b[i] += num % 10, num /= 10;
        a[i] = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    cout<<a[m]<<endl;
    return 0;
}