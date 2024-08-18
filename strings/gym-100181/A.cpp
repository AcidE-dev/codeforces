#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4 + 10;
const int INF = 1e9;

long long n, m, ans;


int z_function(string s) {
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
    return *max_element(z.begin(), z.end());
}

void solve() {
    string s, t, w;
    while (cin >> s) {
        cin >> w;
        for (auto &c: w) c = tolower(c);
        if (s == "?") {
            cout << (z_function(w + '#' + t) == (int) w.size() ? "YES" : "NO") << endl;
        } else {
            t += w;
        }
    }
}



int main() {
    freopen("nenokku_easy.in", "rt", stdin);
    freopen("nenokku_easy.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
