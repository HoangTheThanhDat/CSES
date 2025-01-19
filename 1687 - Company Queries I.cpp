#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;
const int lg = 19;

int n , q , u , k , par[lg + 1][maxn];

int getbit(int n , int i) {
        return (n >> i) & 1;
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 2 ; i <= n ; i++) {
                cin >> u;
                par[0][i] = u;
        }


        for (int i = 1 ; i <= lg ; i++) 
                for (int j = 1 ; j <= n ; j++) par[i][j] = par[i - 1][par[i - 1][j]];

        while (q--) {
                cin >> u >> k;

                for (int i = 0 ; i <= lg ; i++) 
                        if (getbit(k , i) == 1) u = par[i][u];
                
                cout << (u == 0 ? -1 : u) << '\n';
        }

        return 0;
}