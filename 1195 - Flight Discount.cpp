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

const int maxn = 1e5 + 68;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n , m , u , v , w;
vector<pair<int , int>> e[maxn];
pair<int , int> trace[maxn];
ll d[maxn][2];

void dijkstra(int s) {
	priority_queue<pair<pair<ll , int> , bool> , vector<pair<pair<ll , int> , bool>> , greater<pair<pair<ll , int> , bool>>> pq;
	pq.push(make_pair(make_pair(0 , s) , false));

	reset(d , 0x3f);

	d[s][false] = 0;

	while (pq.size() > 0) {
		ll D = pq.top().fi.fi;
		int u = pq.top().fi.se;
		bool sale = pq.top().se;

		pq.pop();

		if (d[u][sale] < D) continue;

		for (pair<int , int> p : e[u]) {
			int v = p.fi;
			int w = p.se;

			if (d[v][sale] > d[u][sale] + w) 	
				d[v][sale] = d[u][sale] + w , 
				pq.push(make_pair(make_pair(d[v][sale] , v) , sale));

			if (!sale) 	
				if (d[v][!sale] > d[u][sale] + w / 2) 
					d[v][!sale] = d[u][sale] + w / 2 , 
					pq.push(make_pair(make_pair(d[v][!sale] , v) , !sale));
		}
	}
}

void solve() {
	cin >> n >> m;

	for (int i = 1 ; i <= m ; i++) {
		cin >> u >> v >> w;
		
		e[u].push_back(make_pair(v , w));
	}

	dijkstra(1);

	cout << d[n][true] << el;
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