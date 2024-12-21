#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n;
pair<int , int> a[maxn];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) cin >> a[i].first >> a[i].second;

        sort(a + 1 , a + n + 1 , [](pair<int , int> &x , pair<int , int> &y) {
                return x.second < y.second;
        });

        int ans = 1 , cur = a[1].second;

        for (int i = 2 ; i <= n ; i++) 
                if (a[i].first >= cur) ++ans , cur = a[i].second;
        
        cout << ans;

        return 0;
}
