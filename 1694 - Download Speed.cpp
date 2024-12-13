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

const int maxn = 555;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , m , u , v , trace[maxn];
ll c[maxn][maxn];
vector<int> e[maxn];

ll bfs(int s = 1 , int t = n) {
        fill(trace , trace + n + 1 , 0);

        trace[s] = -1;

        queue<pair<int , ll>> q;

        q.push(make_pair(s , infll));

        while (q.size() > 0) {
                int u = q.front().fi;
                ll f = q.front().se;

                q.pop();

                for (int v : e[u]) 
                        if (trace[v] == 0 && c[u][v] != 0) {
                                trace[v] = u;

                                ll augment = min(f , c[u][v]);

                                if (v == t) return augment;

                                q.push(make_pair(v , augment));
                        }
        }

        return 0;
}

ll maxflow(int s = 1 , int t = n) {
        ll res = 0 , augment = 0;

        while (augment = bfs()) {
                res += augment;

                int u = t;

                while (u != s) {
                        int v = trace[u];

                        c[u][v] += augment;
                        c[v][u] -= augment;

                        u = v;
                }
        }

        return res;
}

int val;

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v >> val;

                e[u].push_back(v);
                e[v].push_back(u);

                c[u][v] += val;
        }

        cout << maxflow() << el;
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