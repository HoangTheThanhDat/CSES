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
bool team1[maxn];
bool visited[maxn];

void dfs(int u , bool sta) {
        visited[u] = true;

        team1[u] = sta;

        for (int v : e[u]) 
                if (!visited[v]) 
                        dfs(v , !sta);
}

bool bfs(int x) {
        queue<int> q;

        q.push(x);

        visited[x] = true;

        while (q.size() > 0) {
                int u = q.front();
                q.pop();

                for (int v : e[u]) {
                        if (!visited[v]) {
                                q.push(v);
                                visited[v] = true;
                        }

                        if (team1[v] == team1[u]) return false;
                }
        }

        return true;
}

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v;

                e[u].push_back(v);
                e[v].push_back(u);
        }

        reset(visited , false);

        for (int i = 1 ; i <= n ; i++) 
                if (!visited[i]) 
                        dfs(i , true);

        reset(visited , false);

        for (int i = 1 ; i <= n ; i++) 
                if (!visited[i] ) 
                        if (!bfs(i)) {
                                cout << "IMPOSSIBLE" << el;
                                return;
                        }        

        for (int i = 1 ; i <= n ; i++) 
                cout << (team1[i] == true ? 1 : 2) << " ";
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