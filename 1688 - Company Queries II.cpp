#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;
const int lg = 19;

int n , q , u , v , par[lg + 1][maxn] , deep[maxn];
vector<int> e[maxn];

int getbit(int n , int i) {
        return (n >> i) & 1;
}

void dfs(int u) {
        for (int v : e[u]) deep[v] = deep[u] + 1 , dfs(v);
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 2 ; i <= n ; i++) {
                cin >> u;
                e[u].push_back(i);
                par[0][i] = u;
        }

        for (int i = 1 ; i <= lg ; i++) 
                for (int j = 1 ; j <= n ; j++) par[i][j] = par[i - 1][par[i - 1][j]];

        deep[1] = 0; dfs(1);
        
        while (q--) {
                cin >> u >> v;

                if (deep[u] < deep[v]) swap(u , v);

                int dis = deep[u] - deep[v];

                for (int i = 0 ; i <= lg ; i++) 
                        if (getbit(dis , i) == 1) u = par[i][u];
                
                if (u == v) cout << u;
                else {
                        for (int i = lg ; i >= 0 ; i--) 
                                if (par[i][u] != par[i][v]) 
                                        u = par[i][u] , 
                                        v = par[i][v];
                                
                        cout << par[0][u];
                }

                cout << '\n';
        }

        return 0;
}