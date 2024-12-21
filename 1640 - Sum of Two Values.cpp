#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , x , val;
pair<int , int> a[maxn];
set<pair<int , int>> s;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> x;
        
        for (int i = 1 ; i <= n ; i++) {
                cin >> val;

                a[i] = make_pair(val , i);

                s.insert(a[i]);
        }

        sort(a + 1 , a + n + 1);

        for (int i = 1 ; i <= n ; i++) {
                val = x - a[i].first;

                set<pair<int , int>>::iterator y = s.lower_bound(make_pair(val , a[i].second + 1));

                if (y != s.end()) 
                        if (y->first == val) {
                                cout << min(a[i].second , y->second) << " " << max(a[i].second , y->second);
                                return 0;
                        }
        }

        cout << "IMPOSSIBLE";

        return 0;
}
