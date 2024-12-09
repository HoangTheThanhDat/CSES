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

const int maxn = (1 << 15) + 68;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n;
vector<pair<int , int>> e[maxn];
stack<int> st;
vector<int> path;
bool vis[maxn];

void solve() {
        cin >> n;

        int curid = 0;
        
        for (int mask = 0 ; mask < (1 << (n - 1)) ; ++mask) {
                e[mask].push_back(make_pair((mask & ((1 << (n - 2)) - 1)) << 1 , ++curid));
                e[mask].push_back(make_pair(((mask & ((1 << (n - 2)) - 1)) << 1) | 1 , ++curid));
        }

        st.push(0);

        reset(vis , false);

        while (st.size() > 0) {
                bool ok = true;

                int u = st.top();

                while (e[u].size() > 0) {
                        int v = e[u].back().fi;
                        int id = e[u].back().se;

                        e[u].pop_back();

                        if (!vis[id]) {
                                vis[id] = true;

                                st.push(v);

                                ok = false;

                                break;
                        }
                }

                if (ok) path.push_back(u) , st.pop();
        }

        reverse(path.begin() , path.end());

        for (int i = 1 ; i < n ; i++) cout << 0;

        for (int i = 1 ; i < path.size() ; i++) cout << (path[i] & 1);
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