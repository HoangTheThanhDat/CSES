#include <bits/stdc++.h>

using namespace std;

#define      ll      long long
#define      fi      first 
#define      se      second 
#define      el      '\n'

#define reset(__a , __v) memset(__a,__v,sizeof(__a))
#define datmacoder int32_t main()
#define opf(__dat) if (fopen(__dat".inp","r")){freopen(__dat".inp","r",stdin);freopen(__dat".out","w",stdout);}
#define openfile(__dat) opf(__dat);int _t;if(!TESTCASE)_t=1;else cin>>_t;while(_t--){solve();} 

template<class A,class B> inline void maximize(A& x, B y) {x = max(x, y);};
template<class A,class B> inline void minimize(A& x, B y) {x = min(x, y);};

const int maxn = 2e5 + 68;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , m , u , v , w;
pair<pair<int , int> , int> a[maxn];

struct DSU {
        int par[maxn];

        DSU(int n) {
                for (int i = 1 ; i <= n ; i++) par[i] = i;
        }

        int find(int u) {
                return par[u] == u ? u : par[u] = find(par[u]);
        }

        bool join(int u , int v) {
                u = find(u);
                v = find(v);

                if (u == v) return false;

                par[u] = v;

                return true;
        }
};

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v >> w;

                a[i] = make_pair(make_pair(u , v) , w);
        }

        sort(a + 1 , a + m + 1 , [](pair<pair<int , int> , int> x , pair<pair<int , int> , int> y) {
                return x.se < y.se;
        });

        ll ans = 0;

        DSU dsu(n);

        for (int i = 1 ; i <= m ; i++) {
                u = a[i].fi.fi;
                v = a[i].fi.se;
                w = a[i].se;

                if (dsu.join(u , v) == true) 
                        ans += w;
        }

        int par1 = dsu.find(1);

        bool ok = true;

        for (int i = 2 ; i <= n ; i++) 
                if (dsu.find(i) != par1) {
                        ok = false;
                        break;
                }

        if (ok) 
                cout << ans << el;
        else 
                cout << "IMPOSSIBLE" << el;

}

datmacoder {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        openfile("nofile");

        return 0;
}

/* 
        d a t m a . _ c o d e r
        H O A N G   T H E   T H A N H   D A T
*/