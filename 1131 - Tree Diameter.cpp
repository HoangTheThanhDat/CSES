#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , u , v , ans , deepmax[maxn];
vector<int> e[maxn];

void dfs(int u , int p = 0) {
        for (int v : e[u]) 
                if (v != p) 
                        dfs(v , u);
        
        int res1 = 0 , res2 = 0;

        for (int v : e[u]) 
                if (v != p) 
                        if (deepmax[v] > res1) res2 = res1 , res1 = deepmax[v];
                        else if (deepmax[v] > res2) res2 = deepmax[v];

        ans = max(ans , res1 + res2);
        deepmax[u] = res1 + 1;
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
        
        ans = 0;

        dfs(1);

        cout << ans;

        return 0;
}