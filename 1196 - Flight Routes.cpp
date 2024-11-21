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

int n , m , k , u , v , w , visited[maxn];
vector<pair<int , int>> e[maxn];

void solve() {
	cin >> n >> m >> k;

	for (int i = 1 ; i <= m ; i++) {
		cin >> u >> v >> w;
		e[u].push_back(make_pair(v , w));
	}

	priority_queue<pair<ll , int> , vector<pair<ll , int>> , less<pair<ll , int>>> pq;

	pq.push(make_pair(0 , 1));

	reset(visited , 0);

	while (pq.size() > 0 && visited[n] < k) {
		int u = pq.top().se;
		ll D = pq.top().fi;
		pq.pop();

		++visited[u];

		if (u == n) cout << -D << " ";

		if (visited[u] <= k) 
			for (pair<int , int> p : e[u]) {
				int v = p.fi;
				int w = p.se;	

				pq.push(make_pair(D - w , v));
			}
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