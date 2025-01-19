#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;
const int lg = 19;

int n , q , u , v , deep[maxn] , par[lg + 1][maxn];
vector<int> e[maxn];

int getbit(int n , int i) {
        return (n >> i) & 1;
}

void dfs(int u , int p) {
        for (int v : e[u]) 
                if (v != p) {
                        par[0][v] = u;
                        deep[v] = deep[u] + 1;
                        dfs(v , u);
                }
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 1 ; i < n ; i++) {
                cin >> u >> v;
                e[u].push_back(v);
                e[v].push_back(u);
        }        

        deep[1] = 0; par[0][1] = 0; dfs(1 , 0);

        for (int i = 1 ; i <= lg ; i++) 
                for (int j = 1 ; j <= n ; j++) par[i][j] = par[i - 1][par[i - 1][j]];

        while (q--) {
                cin >> u >> v;

                int ans = 0;

                if (deep[u] < deep[v]) swap(u , v);

                int dis = deep[u] - deep[v];

                for (int i = 0 ; i <= lg ; i++) 
                        if (getbit(dis , i) == 1) u = par[i][u] , ans += 1 << i;

                if (u == v) cout << ans;
                else {
                        for (int i = lg ; i >= 0 ; i--) 
                                if (par[i][u] != par[i][v]) 
                                        u = par[i][u] , 
                                        v = par[i][v] , 
                                        ans += 1 << (i + 1);
                                
                        cout << ans + 2;
                }            

                cout << '\n';
        }

        return 0;
}