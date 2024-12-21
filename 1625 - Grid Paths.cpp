#include <bits/stdc++.h>

using namespace std;

const int maxn = 7 + 2;
const int dx[] = {0 , 0 , 1 , -1};
const int dy[] = {1 , -1 , 0 , 0};

string s;
bool vis[maxn][maxn];

bool check(int x , int y) {
        if (vis[x][y] == true) return true;

        int cnt = 0;

        for (int k = 0 ; k < 4 ; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx > 0 && ny > 0 && nx <= 7 && ny <= 7 && !vis[nx][ny]) ++cnt;
        }

        if (x == 7 && y == 1 && cnt > 0) return true;

        if (cnt < 2) return false;

        return true;
}

bool CHECK(int x , int y) {
        int col = 0 , row = 0;

        if (x - 1 > 0 && !vis[x - 1][y]) ++row;
        if (x + 1 <= 7 && !vis[x + 1][y]) ++row;

        if (y - 1 > 0 && !vis[x][y - 1]) ++col;
        if (y + 1 <= 7 && !vis[x][y + 1]) ++col;

        if (row == 2 && col == 0) return false;
        if (row == 0 && col == 2) return false;

        return true;
}

bool CrossCheck(int x , int y) {
        if (x - 1 > 0 && y - 1 > 0) 
                if (!check(x - 1 , y - 1)) return false;
        
        if (x - 1 > 0 && y + 1 <= 7) 
                if (!check(x - 1 , y + 1)) return false;

        if (x + 1 <= 7 && y - 1 > 0) 
                if (!check(x + 1 , y - 1)) return false;
        
        if (x + 1 <= 7 && y + 1 <= 7) 
                if (!check(x + 1 , y + 1)) return false;
        
        return true;
}

int ans = 0;

void rec(int idx , int x , int y) {
        if (vis[x][y] == true) return;

        if (x == 0 || x == 8 || y == 0 || y == 8) return;

        if (idx < 7 * 7 && x == 7 && y == 1) return;

        vis[x][y] = true;

        if (!CrossCheck(x , y)) {
                vis[x][y] = false;
                return;
        }

        if (!CHECK(x , y)) {
                vis[x][y] = false;
                return;
        }

        if (idx == 7 * 7) 
                ++ans;
        else 
                if (s[idx] == '?') 
                        for (int k = 0 ; k < 4 ; k++) 
                                rec(idx + 1 , x + dx[k] , y + dy[k]);
                else 
                        if (s[idx] == 'U') rec(idx + 1 , x - 1 , y);
                        else if (s[idx] == 'D') rec(idx + 1 , x + 1 , y);
                        else if (s[idx] == 'L') rec(idx + 1 , x , y - 1);
                        else if (s[idx] == 'R') rec(idx + 1 , x , y + 1);
                
        vis[x][y] = false;
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> s;

        s = " " + s;

        memset(vis , false , sizeof vis);

        rec(1 , 1 , 1);

        cout << ans;

        return 0;
}
