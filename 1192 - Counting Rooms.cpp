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

int n , m;
char ch[maxn][maxn];
bool visited[maxn][maxn];

void loang(int i , int j) {
        visited[i][j] = true;

        if (i + 1 <= n && !visited[i + 1][j]) loang(i + 1 , j);
        if (i - 1 > 0 && !visited[i - 1][j]) loang(i - 1 , j);
        if (j + 1 <= m && !visited[i][j + 1]) loang(i , j + 1);
        if (j - 1 > 0 && !visited[i][j - 1]) loang(i , j - 1);
}

void solve() {
        cin >> n >> m;

        reset(visited , false);

        for (int i = 1 ; i <= n ; i++) 
                for (int j = 1 ; j <= m ; j++) {
                        cin >> ch[i][j];
                        if (ch[i][j] == '#') visited[i][j] = true;
                }

        int ans = 0;

        for (int i = 1 ; i <= n ; i++) 
                for (int j = 1 ; j <= m ; j++) 
                        if (!visited[i][j]) 
                                ++ans , 
                                loang(i , j);

        cout << ans;
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