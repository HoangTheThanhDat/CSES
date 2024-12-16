#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , q , a[maxn] , l , r , curpos[maxn] , pos[maxn] , ans[maxn];
vector<int> zip;
bool _exist[maxn];

struct dataquery {
        int l , r , idx;
} Q[maxn];

struct BIT {
        int bit[maxn];

        void update(int idx , int val) {
                for (; idx <= n ; idx += idx & -idx) bit[idx] += val;
        }

        int get(int idx) {
                int res = 0;

                for (; idx > 0 ; idx &= idx - 1) res += bit[idx];

                return res;
        }
} fenwick;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) {
                cin >> a[i];

                zip.push_back(a[i]);
        }

        sort(zip.begin() , zip.end());
        zip.resize(unique(zip.begin() , zip.end()) - zip.begin());

        for (int i = n ; i > 0 ; i--) {
                a[i] = lower_bound(zip.begin() , zip.end() , a[i]) - zip.begin() + 1;

                pos[i] = curpos[a[i]];
                curpos[a[i]] = i;
        }

        for (int i = 1 ; i <= q ; i++) {
                cin >> l >> r;

                Q[i] = {l , r , i};
        }

        sort(Q + 1 , Q + q + 1 , [](const dataquery &x , const dataquery &y) {
                return x.l < y.l || x.l == y.l && x.r < y.r;
        });

        fill(_exist , _exist + n + 1 , false);
        
        for (int i = 1 ; i <= n ; i++) {
                if (!_exist[a[i]]) 
                        fenwick.update(i , 1);
                
                _exist[a[i]] = true;
        }

        int cur = 1;

        for (int i = 1 ; i <= q ; i++) {
                l = Q[i].l;
                r = Q[i].r;

                int idx = Q[i].idx;

                while (cur < l) {
                        fenwick.update(cur , -1);

                        if (pos[cur] != 0) fenwick.update(pos[cur] , 1);

                        ++cur;
                }

                ans[idx] = fenwick.get(r) - fenwick.get(l - 1);
        }

        for (int i = 1 ; i <= q ; i++) cout << ans[i] << '\n';

        return 0;
}