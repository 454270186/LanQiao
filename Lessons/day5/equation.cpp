#include <bits/stdc++.h>
using namespace std;
double a, b, c, d;
double y(double x){return a * x * x * x + b * x * x + c * x + d;}
int main()
{
    //cin >> a >> b >> c >> d;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    for (int i = -100; i < 100; i++)
    {
        double left = i, right = i + 1;
        double y1 = y(left), y2 = y(right);
        if (y1 == 0)
        {
            printf("%.2lf ", left);
        }
        if (y1 * y2 < 0)
        { // 小区间内有根
            for (int j = 0; j < 100; j++)
            { // 在小区间内二分
                double mid = (left + right) / 2;
                if (y(mid) * y(right) <= 0)
                    left = mid;
                else
                    right = mid;
            }
            printf("%.2lf ", right);
        }
    }
    return 0;
}