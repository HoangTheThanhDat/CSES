#include <bits/stdc++.h>

using namespace std;

string st;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> st;

        sort(st.begin() , st.end());

        set<string> s;

        do {
                s.insert(st);
        } while (next_permutation(st.begin() , st.end()));

        cout << s.size() << '\n';

        for (string res : s) cout << res << '\n';

        return 0;
}
