#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

int dp[MAXN];
int n;

void solve() {
    cin >> n;
    cin >> dp[1];
    
    for (int i = 2; i <= n; i++) {
        cin >> dp[i];
        dp[i] += max(dp[i - 1], dp[i - 2]);
    }
    
    cout << dp[n];
}

int main() {
    freopen("ladder.in", "rt", stdin);
    freopen("ladder.out", "wt", stdout);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
