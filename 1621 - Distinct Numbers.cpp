#include <bits/stdc++.h>

using namespace std;

int n , val;
set<int> s;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) {
                cin >> val;
                s.insert(val);
        }

        cout << s.size();

        return 0;
}
