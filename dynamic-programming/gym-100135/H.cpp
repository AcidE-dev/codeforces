#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e3 + 10;
const int INF = 1e9;

int dp[MAXN][MAXN];
long long n, m, ans;

void solve() {
    cin >> n;
    for (int i = 0; i <= n; i++) ans += dp[n][i];
    cout << ans;
}

void precalc() {
    dp[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= (i - j) / 2; k++) {
                dp[i][i - j] += dp[j][k];
            }
        }
    }

}

int main() {
    freopen("peacefulsets.in", "rt", stdin);
    freopen("peacefulsets.out", "wt", stdout);
    precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
