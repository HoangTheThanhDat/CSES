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
vector<bool> visited(maxn , false);
int trace[maxn];

void get_path(int _end , int _start) {
	vector<int> path;

	int u = _end;

	while (u != _start) {
		path.push_back(u);
		u = trace[u];
	}

	path.push_back(u);

	cout << path.size() + 1 << el;

	for (int i = path.size() - 1 ; i >= 0 ; i--) 
		cout << path[i] << " ";

	cout << path.back();
}

void dfs(int u , int last) {
	visited[u] = true;

	for (int v : e[u]) 
		if (v != last) {
			if (visited[v] == true) get_path(u , v), exit(0);

			trace[v] = u;

			dfs(v , u);
		}
}

void solve() {
	cin >> n >> m;

	for (int i = 1 ; i <= m ; i++) {
		cin >> u >> v;

		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i = 1 ; i <= n ; i++) 
		if (!visited[i]) 
			dfs(i , 0);

	cout << "IMPOSSIBLE" << el;
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