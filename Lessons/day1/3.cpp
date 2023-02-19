#include <bits/stdc++.h>
using namespace std;

int main() {
    char paper;
    int nums;
    cin >> paper >> nums;
    int longside = 1189;
    int shortside = 841;

    for (int i = 0; i < nums; i++) {
        longside /= 2;
        swap(longside, shortside);
    }

    cout << longside << '\n' << shortside << '\n';

    return 0;
}