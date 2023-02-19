#include <bits/stdc++.h>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int pass_num = 0, good_num = 0;
  int nums;
  cin >> nums;

  for (int i = 0; i < nums; i++) {
    int score;
    cin >> score;

    if (score >= 60) pass_num++;
    if (score >= 85) good_num++;
  }

  cout << setprecision(0) << fixed << (1.0 * pass_num) / nums * 100 << "%\n";
  cout << setprecision(0) << fixed << (1.0 * good_num) / nums * 100 << "%\n";
  


  return 0;
}
