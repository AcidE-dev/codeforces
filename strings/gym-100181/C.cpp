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
    string s, w;
    int ans = 0;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        w = s[i] + w;
        auto z = z_function(w);
        ans += w.size() - *max_element(z.begin(), z.end());
    }
    cout << ans;
}



int main() {
    freopen("unequal.in", "rt", stdin);
    freopen("unequal.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
