#include <bits/stdc++.h>

using namespace std;

const int maxn = 20 + 2;

int n , a[maxn];
long long sum = 0;

int getbit(int n , int i) {
        return (n >> i) & 1;
}

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) {
                cin >> a[i];
                sum += a[i];
        }

        long long ans = 1e18;

        for (int mask = 0 ; mask < (1 << n) ; mask++) {
                long long s = 0;

                for (int j = 0 ; j < n ; j++) 
                        if (getbit(mask , j) & 1) 
                                s += a[j];
                        
                ans = min(ans , abs(sum - 2 * s));      
        }

        cout << ans;

        return 0;
}
