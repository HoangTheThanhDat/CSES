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
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , m , u , v , q , weight;
ll w[maxn][maxn];

void FloydWarshall(void) {
        for (int k = 1 ; k <= n ; k++) 
                for (int u = 1 ; u <= n ; u++) 
                        for (int v = 1 ; v <= n ; v++) 
                                if (w[u][v] > w[u][k] + w[k][v])
                                        w[u][v] = w[u][k] + w[k][v];
}

void solve() {
        cin >> n >> m >> q;

        reset(w , 0x3f);

        for (int i = 1 ; i <= n ; i++) w[i][i] = 0;

        for (int i = 1 ; i <= m ; i++)
                cin >> u >> v >> weight , 
                minimize(w[u][v] , 1ll * weight) , 
                w[v][u] = w[u][v];

        FloydWarshall();

        for (int i = 1 ; i <= q ; i++) {
                cin >> u >> v;

                cout << (w[u][v] == 0x3f3f3f3f3f3f3f3f ? -1 : w[u][v]) << el;
        }
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