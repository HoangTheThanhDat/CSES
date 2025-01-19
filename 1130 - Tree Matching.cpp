#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , u , v , ans;
vector<int> e[maxn];
bool vis[maxn];

void dfs(int u , int p) {
        for (int v : e[u]) 
                if (v != p) {
                        dfs(v , u);
                        if (!vis[v] && !vis[u]) ++ans , vis[v] = vis[u] = true;
                }
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i < n ; i++) {
                cin >> u >> v;
                e[u].push_back(v);
                e[v].push_back(u);
        }

        fill(vis , vis + n + 1 , false);
        vis[0] = true;
        ans = 0;
        dfs(1 , 0);

        cout << ans;

        return 0;
}