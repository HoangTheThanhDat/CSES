#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first 
#define se second 
#define el '\n'
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

int n , m , u , v;
ll w;
vector<ll> d(maxn , -oo);
vector<pair<int , pair<int , int>>> e;

ll bellman_ford(int _start , int _end) {
        d[_start] = 0;
        
        for (int i = 1 ; i < n ; i++) 
                for (pair<int , pair<int , int>> pii : e) {
                        int u = pii.se.fi;
                        int v = pii.se.se;
                        ll  w = pii.fi;

                        if (d[u] != -oo && d[v] < d[u] + w) 
                                d[v] = d[u] + w;
                }
        
        for (int i = 1 ; i <= n ; i++) 
                for (pair<int , pair<int , int>> pii : e) {
                        int u = pii.se.fi;
                        int v = pii.se.se;
                        ll  w = pii.fi;

                        if (d[u] != -oo && d[v] < d[u] + w) 
                                d[v] = oo;
                }

        return d[_end];
}

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v >> w;

                e.push_back(make_pair(w , make_pair(u , v)));
        }

        ll short_path = bellman_ford(1 , n);

        cout << (short_path == oo ? -1 : short_path);
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