#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int INF = 1e9;

int dp[MAXN], f[MAXN];
int n;

void solve() {
    cin >> n;
    f[0] = 1;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '"' && f[i]) dp[i]++;
        if (c == 'w' || !f[i]) {dp[i] = -1; continue;}
        for (int delta: {1, 3, 5}) {
            dp[i + delta] = max(dp[i], dp[i + delta]);
            f[i + delta] = 1;
        }
    }
    cout << dp[n - 1];
}

int main() {
    freopen("lepus.in", "rt", stdin);
    freopen("lepus.out", "wt", stdout);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
