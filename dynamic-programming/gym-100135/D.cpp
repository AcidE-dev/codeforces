#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
const int INF = 1e9;

int dp[MAXN][MAXN];
int n, m;

void solve() {
    //cin >> n >> m;
    for (int i = 7; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            cin >> dp[i][j];
        }
    }
    for (int i = 1; i < 8; i++) {
        dp[0][i] += dp[0][i - 1];
        dp[i][0] += dp[i - 1][0];
    }
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            dp[i][j] += min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        }
    }
    cout << dp[7][7];
}

int main() {
    freopen("king2.in", "rt", stdin);
    freopen("king2.out", "wt", stdout);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
