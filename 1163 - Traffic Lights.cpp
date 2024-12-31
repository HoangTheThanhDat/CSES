#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , x , val;
set<pair<int , int> , greater<pair<int , int>>> s;
set<int> dis;
unordered_map<int , int> dd;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n >> x;

        s.insert(make_pair(1 , n));

        dis.insert(n);
        ++dd[n];

        for (int i = 1 ; i <= x ; i++) {
                cin >> val;

                set<pair<int , int> , greater<pair<int , int>>>::iterator it = s.lower_bound(make_pair(val , n + 1));

                int fi = it->first , se = it->second;

                --dd[se];

                if (dd[se] == 0) dis.erase(se);

                s.erase(it);

                s.insert(make_pair(fi , val - fi + 1));
                dis.insert(val - fi + 1);
                ++dd[val - fi + 1];

                s.insert(make_pair(val + 1 , se - val + fi - 1));
                dis.insert(se - val + fi - 1);
                ++dd[se - val + fi - 1];

                cout << *dis.rbegin() << ' ';
        }

        return 0;
}
