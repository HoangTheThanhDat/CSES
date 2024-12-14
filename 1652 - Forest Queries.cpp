#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 68;

int n , q , u , v , x , y;
char c[maxn][maxn];
int prefix[maxn][maxn];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) 
                for (int j = 1 ; j <= n ; j++) {
                        cin >> c[i][j];

                        prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];

                        if (c[i][j] == '*') ++prefix[i][j];
                }

        while (q--) {
                cin >> u >> v >> x >> y;

                cout << prefix[x][y] - prefix[u - 1][y] - prefix[x][v - 1] + prefix[u - 1][v - 1] << '\n';
        }

        return 0;
}