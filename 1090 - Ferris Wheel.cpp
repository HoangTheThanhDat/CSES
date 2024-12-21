#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , a[maxn] , x;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> x;

        for (int i = 1 ; i <= n ; i++) cin >> a[i];

        sort(a + 1 , a + n + 1);

        int i = 1 , j = n , ans = 0;

        while (i < j) 
                if (a[i] + a[j] <= x) 
                        ++ans , --j , ++i;
                else 
                        --j;
                
        cout << n - ans;

        return 0;
}
