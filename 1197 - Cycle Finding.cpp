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

const int maxn = 2500 + 68;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , m , u , v , w , trace[maxn];
vector<pair<int , pair<int , int>>> e;
ll d[maxn];
vector<int> neg_cycle;

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v >> w;

                e.push_back(make_pair(w , make_pair(u , v)));
        }

        reset(d , 0x3f);

        d[1] = 0;

        reset(trace , -1);

        int neg_start = -1;

        for (int i = 1 ; i <= n && neg_start != 0 ; i++) {
                neg_start = 0;
                
                for (pair<int , pair<int , int>> p : e) {
                        int u = p.se.fi;
                        int v = p.se.se;
                        int w = p.fi;

                        if (d[v] > d[u] + w) 
                                d[v] = d[u] + w ,
                                trace[v] = u ,
                                neg_start = v;
                }
        }

        if (neg_start == 0) 
                return void(cout << "NO");

        int u = neg_start;

        for (int i = 1 ; i < n ; i++) 
                u = trace[u];

        for (int v = u ;; v = trace[v]) {
                neg_cycle.push_back(v);

                if (v == u && (int)neg_cycle.size() > 1) break;
        }

        reverse(neg_cycle.begin() , neg_cycle.end());

        cout << "YES" << el;

        for (int i : neg_cycle) cout << i << " ";
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
