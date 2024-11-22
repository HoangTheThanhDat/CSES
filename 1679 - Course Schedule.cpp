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

int n , m , u , v , cnt_par[maxn];
vector<int> e[maxn];

vector<int> topo_sort(void) {
        vector<int> topo;

        queue<int> q;

        for (int i = 1 ; i <= n ; i++) {
                if (cnt_par[i] == 0) q.push(i);
        }

        while (q.size() > 0) {
                int u = q.front(); q.pop();

                topo.push_back(u);

                for (int v : e[u]) {
                        --cnt_par[v];
                        if (cnt_par[v] == 0) q.push(v);
                }
        }

        return topo;
}

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v;

                e[u].push_back(v);

                ++cnt_par[v];
        }

        vector<int> path = topo_sort();

        if (path.size() != n) 
                cout << "IMPOSSIBLE";
        else 
                for (int i : path) 
                        cout << i << " ";
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