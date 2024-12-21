#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , a[maxn] , b[maxn];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) cin >> a[i] >> b[i];

        sort(a + 1 , a + n + 1);
        sort(b + 1 , b + n + 1);

        int ans = 0 , c = 0 , i = 1 , j = 1;

        while (i <= n && j <= n) {
                if (a[i] < b[j]) 
                        ++c , ++i;
                else 
                        --c , ++j;
                
                ans = max(ans , c);
        }

        cout << ans;

        return 0;
}
