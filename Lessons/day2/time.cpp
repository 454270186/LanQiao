#include <bits/stdc++.h>
using namespace std;
int days_per_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check_day(int day) {
    int month = day / 100;
    int dd = day % 100;

    int day_per_m = days_per_month[month];
    if (month < 1 || month > 12) return false;
    if (dd < 1 || dd > day_per_m) return false;

    return true;
}

bool check_time(int time) {
    int hh = time / 100;
    int mm = time % 100;

    if (hh < 0 || hh > 23) return false;
    if (mm < 0 || mm > 59) return false;

    return true;
}


int main() {
    int ans = 0;

    for (int a = 0; a <= 9; a++) {
        for (int b = 0; b <= 9; b++) {
            if (a == b) continue;
            
            int N_Y = 4, N_D = 0, N_T = 0;
            int A[4] = {a, a, a, a};
            for (int i = 0; i < 4; i++) {
                A[i] = b;
                int number = 0;
                for (int j = 0; j < 4; j++) {
                    number = number * 10 + A[j];
                }
                N_D += check_day(number);
                N_T += check_time(number);

                A[i] = a;
            }
            ans += N_Y * N_D * N_T;
        }
    }

    cout << ans << endl;
    return 0;
}