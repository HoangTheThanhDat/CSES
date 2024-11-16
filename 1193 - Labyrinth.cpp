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

const int maxn = 1000 + 68;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

const int x[] = {1 , -1 , 0 , 0};
const int y[] = {0 , 0 , 1 , -1};

bool visited[maxn][maxn];
char c , par[maxn][maxn] , ans[maxn * maxn];

int n , m , ax , ay , bx , by , dist[maxn][maxn];

queue<pair<int , int>> q;

void solve() {
        cin >> n >> m;

        reset(visited , false);

        for (int i = 1 ; i <= n ; i++) 
                for (int j = 1 ; j <= m ; j++) {
                        cin >> c;

                        if (c == '#') 
                                visited[i][j] = true;
                        
                        if (c == 'A') 
                                ax = i , ay = j;
                        
                        if (c == 'B') 
                                bx = i , by = j;
                }

        visited[ax][ay] = true;

        dist[ax][ay] = 0;

        q.push(make_pair(ax , ay));

        while (q.size() > 0) {
                pair<int , int> top = q.front(); 
                q.pop();

                for (int i = 0 ; i < 4 ; i++) {
                        int dx = top.fi + x[i];
                        int dy = top.se + y[i]; 

                        if (dx > 0 && dx <= n && dy > 0 && dy <= m && !visited[dx][dy]) {
                                if (i == 0) par[dx][dy] = 'D';
                                if (i == 1) par[dx][dy] = 'U';
                                if (i == 2) par[dx][dy] = 'R';
                                if (i == 3) par[dx][dy] = 'L';

                                dist[dx][dy] = dist[top.fi][top.se] + 1;

                                visited[dx][dy] = true;

                                q.push(make_pair(dx , dy));
                        }
                }
        }

        if (!visited[bx][by]) {
                cout << "NO" << el;
                return;
        }

        cout << "YES" << el << dist[bx][by] << el;

        pair<int , int> cur = make_pair(bx , by);

        for (int i = dist[bx][by] ; i > 0 ; i--) {
                ans[i] = par[cur.fi][cur.se];

                if (ans[i] == 'D') cur = make_pair(cur.fi - 1 , cur.se);
                if (ans[i] == 'U') cur = make_pair(cur.fi + 1 , cur.se);
                if (ans[i] == 'R') cur = make_pair(cur.fi , cur.se - 1);
                if (ans[i] == 'L') cur = make_pair(cur.fi , cur.se + 1);
        }

        for (int i = 1 ; i <= dist[bx][by] ; i++) 
                cout << ans[i];
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