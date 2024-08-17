#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int INF = 1e9;

int dp[MAXN][MAXN], a[MAXN][MAXN];
int n, m, ans;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = a[0][0];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
        }
    }
    ans = dp[n - 1][0];
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans;
}

int main() {
    //freopen("king2.in", "rt", stdin);
    //freopen("king2.out", "wt", stdout);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
