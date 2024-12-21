#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> vec;

int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        cin >> n;

        vec.push_back("");

        for (int i = 1 ; i <= n ; i++) {
                int sz = vec.size();

                for (int j = sz - 1 ; j >= 0 ; j--) vec.push_back(vec[j]);

                sz *= 2;

                for (int j = 0 ; j < sz ; j++) 
                        if (j < sz / 2) 
                                vec[j] = '0' + vec[j];
                        else 
                                vec[j] = '1' + vec[j];
        }

        for (int i = 0 ; i < vec.size() ; i++) cout << vec[i] << '\n';

        return 0;
}
