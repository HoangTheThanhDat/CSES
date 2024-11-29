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

int n , m , u , v , low[maxn] , num[maxn] , time_dfs = 0 , ans[maxn] , k = 0;
vector<int> e[maxn];
stack<int> s;

void tarjan(int u) {
        low[u] = num[u] = ++time_dfs;

        s.push(u);

        for (int v : e[u]) {
                if (ans[v] != 0) continue;
                
                if (num[v] == 0) {
                        tarjan(v);
                        minimize(low[u] , low[v]);
                }
                else minimize(low[u] , num[v]);
        }

        if (low[u] == num[u]) {
                ++k;

                int v;

                do {
                        v = s.top();
                        s.pop();

                        ans[v] = k;
                } while (v != u);
        }
}

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v;

                e[u].push_back(v);
        }

        for (int i = 1 ; i <= n ; i++) 
                if (num[i] == 0) 
                        tarjan(i);

        cout << k << el;

        for (int i = 1 ; i <= n ; i++) 
                cout << ans[i] << " ";
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