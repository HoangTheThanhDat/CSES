#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , par , sz[maxn];
vector<int> e[maxn];

void dfs(int u , int p) {
        sz[u] = 0;

        for (int v : e[u]) 
                if (v != p) {
                        dfs(v , u);
                        sz[u] += sz[v] + 1;
                }
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 2 ; i <= n ; i++) {
                cin >> par;
                e[par].push_back(i);
        }

        dfs(1 , 0);

        for (int i = 1 ; i <= n ; i++) cout << sz[i] << ' ';

        return 0;
}