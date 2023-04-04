#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> maze;

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        maze.push_back(temp);
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int x, y;
    cin >> x >> y;
    pair<int, int> start = make_pair(x, y);
    cin >> x >> y;
    pair<int, int> end = make_pair(x, y);

    queue<pair<int, int>> q;
    q.push(start);
    int dis[110][110];
    while (!q.empty()) {
        auto curpos = q.front();
        q.pop();
        int i, j;
        i = curpos.first;
        j = curpos.second;

        if (i == end.first && j == end.second) {
            cout << dis[i][j] << endl;
            return 0;
        }
        vis[i][j] = true;

        // up down left rigth
        if (i-1 >= 0 && i-1 < n && j >= 0 && j < m && !vis[i-1][j]) {
            q.push(make_pair(i-1, j));
            dis[i-1][j] = dis[i][j] + 1;
        }
        if (i+1 >= 0 && i+1 < n && j >= 0 && j < m && !vis[i+1][j]) {
            q.push(make_pair(i+1, j));
            dis[i+1][j] = dis[i][j] + 1;
        }
        if (i >= 0 && i < n && j-1 >= 0 && j-1 < m && !vis[i][j-1]) {
            q.push(make_pair(i, j-1));
            dis[i][j-1] = dis[i][j] + 1;
        }
        if (i >= 0 && i < n && j+1 >= 0 && j+1 < m && !vis[i][j+1]) {
            q.push(make_pair(i, j+1));
            dis[i][j+1] = dis[i][j] + 1;
        }
    }

    cout << -1 << endl;

}