#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fi first 
#define se second 
#define el '\n'
#define reset(__a , __v) memset(__a,__v,sizeof(__a))
#define datmacoder int32_t main()
#define openfile(__dat) if (fopen(__dat".inp","r")){freopen(__dat".inp","r",stdin);freopen(__dat".out","w",stdout);}

template<class A,class B> inline void maximize(A& x, B y) {x = max(x, y);};
template<class A,class B> inline void minimize(A& x, B y) {x = min(x, y);};

const int N = 2e5 + 68;
const int mod = 1e9 + 7;
const int inf = 2e9 + 1e8 + 6688;
const ll oo = 3e18 + 1e17 + 666888;
const bool TESTCASE = false;

//  ------------------- d a t m a . _ c o d e r -------------------  //

int n;
int ans[N] , cnt[2 * N];
pair<pair<int , int> , int> p[N];
vector<int> pos;

void solve() {
        cin >> n;

        for (int i = 1 ; i <= n ; i++) {
                cin >> p[i].fi.fi >> p[i].fi.se;
                p[i].se = i;

                pos.push_back(p[i].fi.fi);
                pos.push_back(p[i].fi.se);
        }

        sort(p + 1 , p + n + 1);

        sort(pos.begin() , pos.end());
        pos.resize(unique(pos.begin() , pos.end()) - pos.begin() + 1);

        int idx = 0 , MAX = 0 , has_been_subtracted = 0;

        for (int i = 1 ; i <= n ; i++) 
                p[i].fi.fi = lower_bound(pos.begin() , pos.end() , p[i].fi.fi) - pos.begin() + 1 ,
                p[i].fi.se = lower_bound(pos.begin() , pos.end() , p[i].fi.se) - pos.begin() + 1;

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

        for (int i = 1 ; i <= n ; i++) {
                if (pq.size() > 0) {
                        pair<int , int> pii = pq.top();

                        if (pii.fi < p[i].fi.fi) {
                                pq.pop();
                                pq.push({p[i].fi.se , pii.se});
                                
                                ans[p[i].se] = pii.se;
                        }
                        else {
                                pq.push({p[i].fi.se , MAX + 1});
                                ++MAX;
                                
                                ans[p[i].se] = MAX;
                        }
                }
                else {
                        pq.push({p[i].fi.se , 1});
                        MAX = 1;

                        ans[p[i].se] = 1;
                }
        }        

        cout << MAX << el;

        for (int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
}

datmacoder {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        openfile("txt");

        int testcase;
        if (!TESTCASE) testcase = 1;
        else cin >> testcase;

        while (testcase--) {
                solve();
        }

        return 0;
}

/* 
        d a t m a . _ c o d e r
        H O A N G   T H E   T H A N H   D A T
*/
