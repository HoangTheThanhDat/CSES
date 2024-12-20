#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , val;
bool ok[maxn];

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        fill(ok + 1 , ok + n + 1 , false);

        for (int i = 1 ; i < n ; i++) {
                cin >> val;
                ok[val] = true;
        }

        for (int i = 1 ; i <= n ; i++) 
                if (!ok[i]) 
                        cout << i;

        return 0;
}
