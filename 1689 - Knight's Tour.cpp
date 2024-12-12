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

const int dx[] = {2 , 2 , 1 , 1 , -2 , -2 , -1 , -1};
const int dy[] = {-1 , 1 , -2 , 2 , 1 , -1 , 2 , -2};

int x , y , a[8 + 1][8 + 1];

int deg(int x, int y) {
        int res = 0;

        for (int i = 0 ; i < 8 ; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx > 0 && ny > 0 && nx <= 8 && ny <= 8 && a[nx][ny] == 0) ++res;
        }

        return res;
}

bool ok(int cnt , int x , int y) {
        a[x][y] = cnt;

        if (cnt == 64) return true;

        vector<tuple<int , int , int>> vec;

        for (int i = 0 ; i < 8 ; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx > 0 && ny > 0 && nx <= 8 && ny <= 8 && a[nx][ny] == 0) 
                        vec.push_back(make_tuple(deg(nx , ny) , nx , ny));
        }

        sort(vec.begin() , vec.end());

        for (tuple<int , int , int> val : vec)
                if (ok(cnt + 1 , get<1>(val) , get<2>(val)) == true) return true;

        a[x][y] = 0;

        return false;
}

void solve() {
        cin >> y >> x;

        ok(1 , x , y);

        for (int i = 1 ; i <= 8 ; i++) {
                for (int j = 1 ; j <= 8 ; j++) cout << a[i][j] << " ";
                cout << el;
        }
        
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