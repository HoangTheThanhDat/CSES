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

int n , m , u , v , low[maxn] , num[maxn] , time_dfs = 0;
bool vis[maxn];
vector<int> e[maxn] , vec;

void tarjan(int u) {
        low[u] = num[u] = ++time_dfs;

        for (int v : e[u]) 
                if (num[v] == 0) {
                        tarjan(v);
                        minimize(low[u] , low[v]);
                }
                else minimize(low[u] , num[v]);

        if (low[u] == num[u]) 
                vec.push_back(u);
}

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v;

                e[u].push_back(v);
        }

        tarjan(1);

        for (int i = 2 ; i <= n ; i++) 
                if (num[i] == 0) 
                        return void(cout << "NO" << el << 1 << " " << i << el);

        if (vec.size() > 1) 
                cout << "NO" << el << vec[0] << " " << vec[1] << el;
        else 
                cout << "YES" << el;
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