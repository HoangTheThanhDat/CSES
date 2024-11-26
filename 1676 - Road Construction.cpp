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

int n , m , a , b;

struct DSU {
        int par[maxn] , sz[maxn] , cnt , mx;

        DSU(int n) {
                for (int i = 1 ; i <= n ; i++) par[i] = i , sz[i] = 1;
                cnt = n;
                mx = 1;
        }

        int find(int u) {
                return par[u] == u ? u : par[u] = find(par[u]);
        }

        bool join(int u , int v) {
                u = find(u);
                v = find(v);

                if (u == v) return false;

                par[v] = u;
                sz[u] += sz[v];
                --cnt;
                maximize(mx , sz[u]);

                return true;
        }
};

void solve() {
        cin >> n >> m;
        
        DSU dsu(n);

        for (int i = 1 ; i <= m ; i++) {
                cin >> a >> b;

                dsu.join(a , b);

                cout << dsu.cnt << " " << dsu.mx << el;
        }
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