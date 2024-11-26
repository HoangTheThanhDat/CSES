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

int n , a[maxn] , deg[maxn] , ans[maxn] , d[maxn];
queue<int> q;
bool vis[maxn] , status;

void dfs(int u) {
        vis[u] = true;

        int v = a[u];

        if (vis[v] == true && ans[v] == 0) {
                ans[v] = d[u] - d[v] + 1;
                ans[u] = ans[v];

                if (u != v) 
                        status = true;
                else    
                        status = false;
        }
        else 
        if (vis[v] == true && ans[v] > 0) {
                ans[u] = ans[v] + 1;
        }
        else {
                d[v] = d[u] + 1;

                dfs(v);

                if (ans[u] > 1) 
                        status = false;
                else {
                        if (status == true) 
                                ans[u] = ans[v];
                        else 
                                ans[u] = ans[v] + 1;
                }
        }
}

void solve() {
        cin >> n;

        for (int i = 1 ; i <= n ; i++) {
                cin >> a[i];
                ans[i] = 0;
                ++deg[a[i]];
        }

        for (int i = 1 ; i <= n ; i++) 
                if (deg[i] == 0) 
                        q.push(i);

        while (q.size() > 0) {
                int u = q.front();
                q.pop();

                status = false;
                d[u] = 0;
                dfs(u);
        }

        for (int i = 1 ; i <= n ; i++)  
                if (ans[i] == 0) 
                        dfs(i);

        for (int i = 1 ; i <= n ; i++) 
                cout << ans[i] << " ";
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