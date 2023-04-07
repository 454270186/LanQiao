#include<iostream>
#include<stack>
using namespace std;
const int N = 25;
int a[N];
int b[N];
int vis[N][N];
int n;
int d[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
stack<int>st;//记录走过的点
bool dfs(int x,int y) {
 
    if (x == n - 1 && y == n - 1) {
            for (int i = 0;i < n;i++) 
              if (a[i] || b[i]) 
            return false;
        return true;
    }
    
    for (int i = 0;i < 4;i++) {
        int tx = x + d[i][0];
        int ty = y + d[i][1];
 
     if (tx < 0 || ty < 0 || tx >= n || ty >= n || vis[tx][ty]||ty!=n-1&&a[ty]==0||tx!=n-1&&b[tx]==0) 
               continue;
            a[ty]--, b[tx]--;//判断走到该格能否满足要求
            vis[tx][ty] = 1;
            st.push(tx*n+ty);
            if (dfs(tx, ty))return true;
            //回溯
            vis[tx][ty] = 0, a[ty]++, b[tx]++, st.pop();
    }
    return false;
}
int main() {
    cin >> n;
    for (int i = 0;i < n;i++)cin >> a[i];//北边 a[ty]方向
    for (int i = 0;i < n;i++)cin >> b[i];//西边,a[tx]方向
    vis[0][0] = 1;
    st.push(0);
    a[0]--,b[0]--;
    
if (dfs(0, 0)){
     stack<int>ans;
    while (!st.empty()) {
        ans.push(st.top());
        st.pop();
    }
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
     }
    }
 return 0;
}