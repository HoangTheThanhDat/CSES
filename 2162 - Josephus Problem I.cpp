#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , idx;
bool vis[maxn];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        if (n == 1) {
                cout << 1;
                return 0;
        }

        idx = 2;

        int c = 0;

        memset(vis , false , sizeof vis);

        while (c < n) {
                ++c;

                cout << idx << ' ';

                if (c == n) return 0;

                vis[idx] = true;

                idx = (idx == n ? 1 : idx + 1);

                while (vis[idx]) idx = (idx == n ? 1 : idx + 1);

                idx = (idx == n ? 1 : idx + 1);
                
                while (vis[idx]) idx = (idx == n ? 1 : idx + 1);
        }

        return 0;
}
