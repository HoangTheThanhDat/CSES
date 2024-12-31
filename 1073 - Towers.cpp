#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 68;

int n , val;
vector<int> vec;
vector<int>::iterator it;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        for (int i = 1 ; i <= n ; i++) {
                cin >> val;

                it = upper_bound(vec.begin() , vec.end() , val);

                if (it == vec.end()) 
                        vec.push_back(val);
                else 
                        vec[it - vec.begin()] = val;
        }

        cout << vec.size();

        return 0;
}
