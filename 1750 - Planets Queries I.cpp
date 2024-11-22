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

const int lg = 31;

int n , x , k , q;
int nxt[lg + 1][maxn];

int getbit(int n , int i) {
	return (n >> i) & 1;
}

void solve() {
	cin >> n >> q;

	for (int i = 1 ; i <= n ; i++) 
		cin >> nxt[0][i];

	for (int i = 1 ; i <= lg ; i++) 
		for (int j = 1 ; j <= n ; j++) 
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];

	while (q--) {
		cin >> x >> k;

		for (int i = lg ; i >= 0 ; i--) 
			if (getbit(k , i) & 1)	
				x = nxt[i][x];
			
		cout << x << el;
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