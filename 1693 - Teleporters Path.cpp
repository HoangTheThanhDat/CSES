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

int n , m , u , v , indeg[maxn] , outdeg[maxn];
vector<pair<int , int>> e[maxn];
bool vis[maxn];

list<int> eulerpath(int u) {
        list<int> ans;

        ans.push_back(u);

        while (e[u].size() > 0) {
                int v = e[u].back().fi;
                int id = e[u].back().se;

                e[u].pop_back();

                if (vis[id] == true) continue;

                vis[id] = true;

                u = v;

                ans.push_back(u);
        }

        for (list<int>::iterator it = ++ans.begin() ; it != ans.end() ; ++it) {
                list<int> t = eulerpath(*it);

                t.pop_back();

                ans.splice(it , t);
        }

        return ans;
}

void solve() {
        cin >> n >> m;

        for (int i = 1 ; i <= m ; i++) {
                cin >> u >> v;

                e[u].push_back(make_pair(v , i));

                ++indeg[v];
                ++outdeg[u];
        }

        for (int i = 2 ; i < n ; i++) 
                if (indeg[i] != outdeg[i]) return void(cout << "IMPOSSIBLE");

        if (indeg[1] + 1 != outdeg[1] || outdeg[n] + 1 != indeg[n]) 
                return void(cout << "IMPOSSIBLE");

        e[n].push_back(make_pair(1 , m + 1));

        list<int> path = eulerpath(1);

        if (path.size() != m + 2) 
                cout << "IMPOSSIBLE";
        else 
                for (list<int>::iterator it1 = path.begin() , it2 = ++path.begin() ; it2 != path.end() ; ++it1 , ++it2) 
                        if (*it1 == n && *it2 == 1) {
                                for (list<int>::iterator it = it2 ; it != path.end() ; ++it) 
                                        cout << *it << " ";
                                
                                for (list<int>::iterator it = ++path.begin() ; it != it2 ; ++it)
                                        cout << *it << " ";

                                return;
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
