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

int n , m , so , ans , u , v;
vector<int> e[maxn];
int d[maxn] , x[maxn] , y[maxn];

bool bfs() {
        queue<int> q;

        for (int u = 1 ; u <= n ; u++) 
                if (!x[u]) 
                        d[u] = 0 , 
                        q.push(u);
                else 
                        d[u] = inf;

        d[0] = inf;

        while (q.size() > 0) {
                u = q.front();
                q.pop();

                for (int v : e[u])      
                        if (d[y[v]] == inf) 
                                d[y[v]] = d[u] + 1 , 
                                q.push(y[v]);
        }

        return d[0] != inf;
}

bool dfs(int u) {
        for (int v : e[u]) {    
                if (!y[v]) {
                        x[u] = v;
                        y[v] = u;
                        d[u] = inf;

                        return true;
                }

                if (d[y[v]] == d[u] + 1) 
                        if (dfs(y[v])) {
                                x[u] = v;
                                y[v] = u;
                                d[u] = inf;

                                return true;
                        }
        }

        d[u] = inf;

        return false;
}

int t;

void solve() {
        cin >> n >> m >> t;

        for (int i = 1 ; i <= t ; i++) {
                cin >> u >> v;

                e[u].push_back(v);
        }

        int ans = 0;

        while (bfs() == true) 
                for (int i = 1 ; i <= n ; i++) 
                        if (!x[i]) 
                                if (dfs(i) == true) ++ans;

        cout << ans << el;

        for (int i = 1 ; i <= n ; i++) 
                if (x[i] != 0) 
                        cout << i << " " << x[i] << el;
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
