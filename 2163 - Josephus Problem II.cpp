#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;
const int maxblock = 500;

struct datablock {
        int l , r , sz;
};

int n , K , c = 0;
datablock block[maxblock];
bool vis[maxn];

int getblock(int i) {
        return (i - 1) / maxblock + 1;
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> K;

        int i = 1;

        while (i + maxblock <= n) {
                ++c;

                block[c].l = i;
                block[c].r = i + maxblock - 1;
                block[c].sz = maxblock;

                i += maxblock;
        }

        if (block[c].r < n) {
                ++c;
                
                block[c].l = block[c - 1].r + 1;
                block[c].r = n;
                block[c].sz = n - block[c - 1].r;
        }

        memset(vis , false , sizeof vis);

        int j = 0;

        i = K % n + 1;

        if (i > n) i = n;

        while (j < n) {
                int cnt = 0;

                cout << i << " ";

                ++j;
                if (j == n) continue;

                int k = K % (n - j);

                vis[i] = true;

                int get = getblock(i);
                --block[get].sz;

                bool stop = false;

                for (int x = i + 1 ; x <= block[get].r ; ++x) 
                        if (!vis[x]) {
                                ++cnt;
                                if (cnt == k + 1) {
                                        i = x;
                                        stop = true;
                                        break;
                                }
                        }
                
                if (stop) continue;

                int x = (get + 1 > c ? 1 : get + 1);

                while (cnt + block[x].sz < k + 1) {
                        cnt += block[x].sz;
                        x = (x + 1 > c ? 1 : x + 1);
                }

                for (int y = block[x].l ; y <= block[x].r ; ++y) 
                        if (!vis[y]) {
                                ++cnt;
                                if (cnt == k + 1) {
                                        i = y;
                                        break;
                                }
                        }
        }

        return 0;
}
