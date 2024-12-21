#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , m , k;
int a[maxn] , b[maxn];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> m >> k;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];
        for (int i = 1 ; i <= m ; i++) cin >> b[i];

        sort(a + 1 , a + n + 1);
        sort(b + 1 , b + m + 1);

        int i = 1 , j = 1 , ans = 0;

        while (i <= n && j <= m) {
                if (a[i] > b[j] + k) 
                        ++j;
                else 
                        if (a[i] < b[j] - k) 
                                ++i;
                        else 
                                ++i , ++j , ++ans;
        }

        cout << ans;

        return 0;
}
