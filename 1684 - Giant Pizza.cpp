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

int n , m , u , v;
char su , sv;

vector<int> e[maxn];

int NOT(int u) {
        return u + (u <= m ? m : -m);
}

int num[maxn] , low[maxn] , id[maxn] , curdfs = 0 , curid = 0;
stack<int> s;

void tarjan(int u) {
        num[u] = low[u] = ++curdfs;

        s.push(u);

        for (int v : e[u])
                if (!id[v]) 
                        if (!num[v]) {
                                tarjan(v);
                                low[u] = min(low[u] , low[v]);
                        }
                        else    
                                low[u] = min(low[u] , num[v]);

        if (num[u] == low[u]) {
                ++curid;

                int v;

                do {
                        v = s.top();
                        s.pop();

                        id[v] = curid;
                } while (v != u);
        }
}

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= n ; i++) {
                cin >> su >> u >> sv >> v;

                if (su == '-') u = NOT(u);
                if (sv == '-') v = NOT(v);

                e[NOT(u)].push_back(v);
                e[NOT(v)].push_back(u);
        }

        for (int i = 1 ; i <= NOT(m) ; i++) 
                if (!id[i]) tarjan(i);

        for (int i = 1 ; i <= m ; i++) 
                if (id[i] == id[NOT(i)]) 
                        return void(cout << "IMPOSSIBLE");

        for (int i = 1 ; i <= m ; i++) 
                cout << (id[i] < id[NOT(i)] ? '+' : '-') << " ";
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
