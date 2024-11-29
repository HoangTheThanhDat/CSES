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

int n , m , u , v , trace[maxn];
vector<int> e[maxn] , path;
bool ok = false;

void get_path(int u) {
        for (int v = trace[u] ; v != u ; v = trace[v])
                path.push_back(v);
        
        reverse(path.begin() , path.end());

        cout << path.size() + 2 << el;
        
        cout << u << " ";

        for (int i : path) cout << i << " "; cout << u;
}

void dfs(int u) {
        for (int v : e[u]) {
                if (trace[v] == -1) continue;
                
                if (trace[v] == u) get_path(v) , ok = true , exit(0);

                trace[v] = u;

                dfs(v);

                trace[v] = -1;
        }
}

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v;

                e[u].push_back(v);
        }

        reset(trace , -1);

        for (int i = 1 ; i <= n ; i++) 
                if (trace[i] == -1) {
                        trace[i] = 0;
                        dfs(i);

                        if (ok) return;
                }

        cout << "IMPOSSIBLE";
}

datmacoder {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        openfile("txt");

        return 0;
}

/* 
        d a t m a . _ c o d e r
        H O A N G   T H E   T H A N H   D A T
*/
