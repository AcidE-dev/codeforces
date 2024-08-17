#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4 + 10;
const int INF = 1e9;

int dp[MAXN];
vector<int> s;
int n, m, ans;

void solve() {
    cin >> m >> n;
    s.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    dp[0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = m; i - s[j] >= 0; i--) {
            if (dp[i - s[j]]) {dp[i] = 1; ans = max(ans, i);}
        }
    }
    cout << ans;
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
