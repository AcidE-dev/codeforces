#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4 + 10;
const int INF = 1e9;


vector<int> z_function(string s) {
    int n = (int) s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;

        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

void solve() {
    string s, t, w;
    vector<int> ans;
    cin >> t >> s;
    auto z = z_function(s + '#' + t);
    for (int i = 0; i < z.size(); i++) {
        if (z[i] == s.size()) {
            ans.push_back(i - s.size());
        }
    }
    cout << ans.size() << endl;
    for (auto el: ans) cout << el << ' ';
}



int main() {
    freopen("search.in", "rt", stdin);
    freopen("search.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
