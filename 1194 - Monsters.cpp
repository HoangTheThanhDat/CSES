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

const int dx[] = {-1 , 1 , 0 , 0};
const int dy[] = {0 , 0 , 1 , -1};
const char go[] = {'U' , 'D' , 'R' , 'L'};

int n , m , trace[maxn][maxn];
char a[maxn][maxn];
queue<pair<int , int>> q;
pair<int , int> pa;

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= n ; i++)  
                for (int j = 1 ; j <= m ; j++) {
                        cin >> a[i][j];

                        if (a[i][j] == 'M') q.push(make_pair(i , j));

                        if (a[i][j] == 'A') pa = make_pair(i , j);
                }

        q.push(pa);

        trace[pa.fi][pa.se] = -1;

        while (q.size() > 0) {
                pair<int , int> p = q.front();
                q.pop();

                if (a[p.fi][p.se] == 'A')       
                        if (p.fi == 1 || p.fi == n || p.se == 1 || p.se == m) {
                                cout << "YES" << el;

                                string path = "";

                                int d = trace[p.fi][p.se];

                                int x = p.fi;
                                int y = p.se;

                                while (d != -1) {
                                        path += go[d];
                                        x -= dx[d];
                                        y -= dy[d];
                                        d = trace[x][y];   
                                }

                                reverse(path.begin() , path.end());

                                cout << path.size() << el << path << el; 
                                return;
                        }

                for (int i = 0 ; i < 4 ; i++) {
                        int x = p.fi + dx[i];
                        int y = p.se + dy[i];

                        if (x == 0 || y == 0 || x == n + 1 || y == m + 1 || a[x][y] != '.') continue;
                        else {
                                a[x][y] = a[p.fi][p.se];

                                if (a[x][y] == 'A') trace[x][y] = i;

                                q.push(make_pair(x , y));
                        }
                }
        }

        cout << "NO" << el;
        return;
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
