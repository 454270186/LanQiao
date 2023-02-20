#include <bits/stdc++.h>
using namespace std;
long num = 1200000;

int main() {
    unordered_set<int> hashset;
    for (long i = 1; i <= num; i++) {
        if (num % i == 0) {
            if (hashset.find(i) != hashset.end()) {
                break;
            }
            hashset.insert(i);
        }
    }

    cout << hashset.size() << endl;
}