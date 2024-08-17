#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4 + 10;
const int INF = 1e9;

long long dp[30][3][3];
long long n, m, ans;

void solve() {
    cin >> n;
    if (n == 0) {
        cout << 1;
        return;
    }
    if (n == 1) {
        cout << 3;
        return;
    }

    
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            dp[0][j][k] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == 0 && k == 1) continue;
                int ad = 0;
                for (int p = 0; p < 3; p++) ad += dp[i - 1][p][j];
                dp[i][j][k] += ad;
            }
        }
    }
    

    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            if (j == 0 && k == 1) continue;
            ans += dp[n - 1][j][k];
        }
    }
    
    cout << ans / 3;
    
}



int main() {
    //freopen("peacefulsets.in", "rt", stdin);
    //freopen("peacefulsets.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
