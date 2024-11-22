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

int n , m , u , v , dp[maxn] , deg[maxn];
vector<int> e[maxn];
bool vis[maxn];
queue<int> q;

void add(int &a , int b) {
	a += b;

	if (a >= mod) a -= mod;
}

void solve() {
	cin >> n >> m;

	for (int i = 1 ; i <= m ; i++) {
		cin >> u >> v;

		e[u].push_back(v);

		++deg[v];
	}

	reset(dp , 0);

	for (int i = 1 ; i <= n ; i++) 
		if (deg[i] == 0) 
			q.push(i);

	dp[1] = 1;

	while (q.size() > 0) {
		int u = q.front();
		q.pop();

		for (int v : e[u]) {
			add(dp[v] , dp[u]);

			--deg[v];

			if (deg[v] == 0) q.push(v);
		}
	}

	cout << dp[n] << el;
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