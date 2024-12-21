#include <bits/stdc++.h>

using namespace std;

int n , m , h , t;
set<pair<int , int> , greater<pair<int , int>>> s;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> m;

        for (int i = 1 ; i <= n ; i++) cin >> h , s.insert(make_pair(h , i));

        for (int i = 1 ; i <= m ; i++) {
                cin >> t;

                set<pair<int , int> , greater<pair<int , int>>>::iterator x = s.lower_bound(make_pair(t , n + 1));

                if (x == s.end()) 
                        cout << -1 << '\n';
                else {
                        cout << x->first << '\n';
                        s.erase(x);
                }
        }

        return 0;
}
