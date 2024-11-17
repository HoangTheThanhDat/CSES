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
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , m , u , v;
vector<int> e[maxn];
int trace[maxn];
vector<bool> visited(maxn , false);

void bfs(int x) {
        queue<int> q;

        q.push(x);

        visited[x] = true;

        while (q.size() > 0) {
                int u = q.front();
                q.pop();

                for (int v : e[u]) 
                        if (!visited[v]) {
                                q.push(v);
                                visited[v] = true;
                                trace[v] = u;
                        }
        }
}

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v;

                e[u].push_back(v);
                e[v].push_back(u);
        }

        bfs(1);

        if (!visited[n]) 
                cout << "IMPOSSIBLE" << el;
        else {
                vector<int> path;

                int u = n;

                while (u != 0) {
                        path.push_back(u);
                        u = trace[u];
                }

                cout << path.size() << el;

                for (int i = path.size() - 1 ; i >= 0 ; i--)   
                        cout << path[i] << " ";
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