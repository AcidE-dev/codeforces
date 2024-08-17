#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;
const int INF = 1e9;

int dp[MAXN], s[MAXN];
int n, m, ans, k = 130;

void solve() {
    cin >> n;
    cout << dp[n] << endl;
}

void precalc() {
    for (int i = 1; i <= k; i++) {
        s[i] = s[i - 1] + (i + 1) * i / 2;
    }
    dp[0] = 0;
    for (int i = 1; i < MAXN; i++) {
        dp[i] = i;
        for (int j = 1; j <= k; j++) {
            if (i - s[j] < 0) break;
            dp[i] = min(dp[i], dp[i - s[j]] + 1);
        }
    }
}

int main() {
    //freopen("king2.in", "rt", stdin);
    //freopen("king2.out", "wt", stdout);
    precalc();
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
