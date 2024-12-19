#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 68;

int n , q , type , x , y , u , v;
char a[maxn][maxn];

struct BIT {
        int bit[maxn][maxn];

        void update(int x , int y , int val) {
                for (; x <= n ; x += x & -x) 
                        for (int Y = y ; Y <= n ; Y += Y & -Y) bit[x][Y] += val;
        }

        int get(int x , int y) {
                int res = 0;

                for (; x > 0 ; x &= x - 1) 
                        for (int Y = y ; Y > 0 ; Y &= Y - 1) res += bit[x][Y];
                
                return res;
        }
} fenwick;      

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) 
                for (int j = 1 ; j <= n ; j++) {
                        cin >> a[i][j];

                        if (a[i][j] == '*') fenwick.update(i , j , 1);
                }
        
        while (q--) {
                cin >> type;

                if (type & 1) {
                        cin >> x >> y;

                        if (a[x][y] == '*') fenwick.update(x , y , -1);
                        else fenwick.update(x , y , 1);

                        a[x][y] = (a[x][y] == '*' ? '.' : '*');
                }
                else {
                        cin >> x >> y >> u >> v;

                        cout << fenwick.get(u , v) - fenwick.get(x - 1 , v) - fenwick.get(u , y - 1) + fenwick.get(x - 1 , y - 1) << '\n';
                }
        }

        return 0;
}