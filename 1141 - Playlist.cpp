#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , a[maxn] , cur , ans;
set<pair<int , int>> s;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        cur = 1; ans = 0;

        for (int i = 1 ; i <= n ; i++) {
                cin >> a[i];

                set<pair<int , int>>::iterator x = s.lower_bound(make_pair(a[i] , -1));

                if (x != s.end() && x->first == a[i]) {
                        for (int j = cur ; j <= x->second ; j++) s.erase(make_pair(a[j] , j));

                        cur = x->second + 1;       
                }

                s.insert(make_pair(a[i] , i));

                ans = max(ans , (int)s.size());
        }

        cout << ans;

        return 0;
}
