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

const int lg = 20;

int n , nxt[lg + 1][maxn] , len[maxn] , q , a , b;

bool vis[maxn];

void bfs(int u) {
        if (vis[u] == true) return;

        len[u] = 0;

        vis[u] = true;

        bfs(nxt[0][u]);

        len[u] = len[nxt[0][u]] + 1;
}

int getbit(int n , int i) {
        return (n >> i) & 1;
}

int get(int u , int len) {
        if (len < 0) return -1;

        for (int i = 0 ; i <= lg ; i++) 
                if (getbit(len , i) & 1) 
                        u = nxt[i][u];

        return u;
}

void solve() {
        cin >> n >> q;

        for (int i = 1 ; i <= n ; i++) 
                cin >> nxt[0][i];

        for (int i = 1 ; i <= lg ; i++) 
                for (int j = 1 ; j <= n ; j++)  
                        nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];

        reset(vis , false);

        for (int i = 1 ; i <= n ; i++) 
                if (!vis[i]) 
                        bfs(i);

        while (q--) {
                cin >> a >> b;

                int x = get(a , len[a]);
                
                if (get(a , len[a] - len[b]) == b)      
                        cout << len[a] - len[b] << el;
                else if (get(x ,  len[x] - len[b]) == b) 
                        cout << len[a] + len[x] - len[b] << el;
                else 
                        cout << -1 << el;
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