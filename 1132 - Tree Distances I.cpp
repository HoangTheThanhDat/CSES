#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , u , v , deepmax[maxn] , ans[maxn];
vector<int> e[maxn];

void dfs(int u , int p) {
        int res = 0;

        for (int v : e[u])
                if (v != p) {
                        dfs(v , u);
                        res = max(res , deepmax[v]);
                }
        
        deepmax[u] = res + 1;      
}

void reroot(int u , int p) {
        ans[u] = deepmax[u] - 1;

        int max1 = 0 , max2 = 0;

        for (int v : e[u])
                if (deepmax[v] > max1) max2 = max1 , max1 = deepmax[v];
                else if (deepmax[v] > max2) max2 = deepmax[v];

        for (int v : e[u]) 
                if (v != p) {
                        int olddeepu = deepmax[u];
                        int olddeepv = deepmax[v];

                        if (deepmax[v] == max1) 
                                deepmax[u] = max2 + 1;
                        else 
                                deepmax[u] = max1 + 1;
                        
                        deepmax[v] = max(deepmax[v] , deepmax[u] + 1);

                        reroot(v , u);

                        deepmax[u] = olddeepu;
                        deepmax[v] = olddeepv;
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

        dfs(1 , 0);
        reroot(1 , 0);

        for (int i = 1 ; i <= n ; i++) cout << ans[i] << ' ';

        return 0;
}