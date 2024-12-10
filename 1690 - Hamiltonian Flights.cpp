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

const int maxn = 20;
const int MASK = (1 << 21) - 1 + 68;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , m , u , v , dp[maxn + 5][MASK];
vector<int> e[maxn + 5];
bool vis[maxn + 5][MASK];

struct dataqueue {
        int u , mask;
};

queue<dataqueue> q;

void add(int &a , int b) {
        a += b;

        if (a >= mod) a -= mod;
}

int getbit(int n , int i) {
        return (n >> i) & 1;
}

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v;

                e[u].push_back(v);
        }

        reset(vis , false);

        dp[1][1] = 1;

        vis[1][1] = true;

        q.push({1 , 1});

        while (q.size() > 0) {
                int u = q.front().u;
                int mask = q.front().mask;

                bitset<10> s(mask);
                
                q.pop();

                for (int v : e[u])
                        if (getbit(mask , v - 1) == 0) {
                                int newmask = mask | (1 << (v - 1));

                                add(dp[v][newmask] , dp[u][mask]);

                                if (!vis[v][newmask]) {
                                        q.push({v , newmask});
                                        vis[v][newmask] = true;
                                }
                        }
        }

        cout << dp[n][(1 << n) - 1];
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