#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , m , a[maxn] , idx[maxn] , ans , x , y , X , Y;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> m;

        idx[0] = 0; idx[n + 1] = n + 1;

        for (int i = 1 ; i <= n ; i++) cin >> a[i] , idx[a[i]] = i;

        ans = 1;

        for (int i = 1 ; i <= n ; i++) 
                if (idx[i - 1] > idx[i]) ++ans;
        
        for (int i = 1 ; i <= m ; i++) {
                cin >> X >> Y;

                x = a[X];
                y = a[Y];

                swap(a[X] , a[Y]);

                if (idx[x - 1] <= idx[x] && idx[x - 1] > Y) ++ans;
                if (idx[x - 1] > idx[x] && idx[x - 1] <= Y) --ans;

                if (idx[x] <= idx[x + 1] && Y > idx[x + 1]) ++ans;
                if (idx[x] > idx[x + 1] && Y <= idx[x + 1]) --ans;

                idx[x] = Y;

                if (idx[y - 1] <= idx[y] && idx[y - 1] > X) ++ans;
                if (idx[y - 1] > idx[y] && idx[y - 1] <= X) --ans;

                if (idx[y] <= idx[y + 1] && X > idx[y + 1]) ++ans;
                if (idx[y] > idx[y + 1] && X <= idx[y + 1]) --ans;

                idx[y] = X;

                cout << ans << '\n';
        }

        return 0;
}
