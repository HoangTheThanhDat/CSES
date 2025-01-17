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

int n , m , u , v , w , dp[maxn] , minpath[maxn] , maxpath[maxn];
vector<pair<int , int>> e[maxn] , e2[maxn];
ll d[maxn];
queue<int> q;
bool vis[maxn];

void add(int &a , int b) {
	a += b;

	if (a >= mod) a -= mod;
}

void dijkstra(int s) {
	priority_queue<pair<ll , int> , vector<pair<ll , int>> , greater<pair<ll , int>>> pq;
	pq.push(make_pair(0 , s));

	reset(d , 0x3f);

	d[s] = 0;

	while (pq.size() > 0) {
		int u = pq.top().se;
		ll D = pq.top().fi;
		
		pq.pop();

		if (d[u] < D) continue;

		for (pair<int , int> p : e[u]) {
			int v = p.fi;
			int w = p.se;

			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				pq.push(make_pair(d[v] , v));
			}
		}
	}
}

void calc(int u) {
	if (dp[u] > 0) {
		return;
	}

	if (u == 1) {
		dp[1] = 1;
		maxpath[1] = minpath[1] = 0;
		return;
	}

	for (pair<int , int> p : e2[u]) {
		int v = p.fi;
		int w = p.se;

		if (d[v] + w == d[u]) {
			calc(v);

			add(dp[u] , dp[v]);
			maximize(maxpath[u] , maxpath[v] + 1);
			minimize(minpath[u] , minpath[v] + 1);
		}
	}
}

void solve() {
	cin >> n >> m;

	for (int i = 1 ; i <= m ; i++) {
		cin >> u >> v >> w;

		e[u].push_back(make_pair(v , w));
		e2[v].push_back(make_pair(u , w));
	}

	dijkstra(1);

	reset(dp , 0);
	reset(minpath , 0x3f);
	reset(maxpath , 0);

	calc(n);

	cout << d[n] << " " << dp[n] << " " << minpath[n] << " " << maxpath[n] << el;
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