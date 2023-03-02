#include <bits/stdc++.h>
using namespace std;

// 贪心，遇到不一样的就把当前的和下一个都翻

string origin, last;
int cnt = 0;
int main() {
    cin >> origin >> last;
    
    for (int i = 0; i < origin.length()-1; i++) {
        if (origin[i] != last[i]) {
            if (origin[i] == '*')
            origin[i] = 'o';
            else 
            origin[i] = '*';

            if (origin[i+1] == '*')
            origin[i+1] = 'o';
            else
            origin[i+1] = '*';

            cnt++;
        }

        //cout << i << ": " << origin << endl;
    }

    cout << cnt <<endl;
}
