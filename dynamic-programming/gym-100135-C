#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int INF = 1e9;

int dp[MAXN][MAXN];
int n, m;

void solve() {
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i + 2][j + 1] += dp[i][j];
            dp[i + 1][j + 2] += dp[i][j];
        }
    }
    cout << dp[n - 1][m - 1];
}

int main() {
    freopen("knight.in", "rt", stdin);
    freopen("knight.out", "wt", stdout);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
