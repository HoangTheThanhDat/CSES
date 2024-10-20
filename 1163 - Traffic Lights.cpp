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

int n , x , so;
set<pair<int , int> , greater<pair<int , int>>> s;
set<int> dis;
unordered_map<int , int> dd;

void solve() {
        cin >> n >> x;

        s.insert({1 , n});
        dis.insert(n);
        ++dd[n];

        for (int i = 1 ; i <= x ; i++) {
                cin >> so;

                set<pair<int , int> , greater<pair<int , int>>>::iterator y = s.lower_bound({so , n + 1});

                int fir = y -> fi , sec = y -> se;

                --dd[sec];

                if (dd[sec] == 0) dis.erase(sec);

                s.erase(y);

                s.insert({fir , so - fir + 1});
                dis.insert(so - fir + 1);
                ++dd[so - fir + 1];

                s.insert({so + 1 , sec - so + fir - 1});
                dis.insert(sec - so + fir - 1);
                ++dd[sec - so + fir - 1];

                cout << *dis.rbegin() << " ";
        }
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
        H O A N G  T H E  T H A N H  D A T
*/
