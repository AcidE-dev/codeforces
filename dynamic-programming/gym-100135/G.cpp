#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4 + 10;
const int INF = 1e9;

vector<int> g[MAXN];
int dp[MAXN];
int n, m, ans;

int dfs(int v) {
    if (dp[v] == -1) {
        dp[v] = 0;
        for (int u: g[v]) {
            dp[v] = max(dp[v], dfs(u) + 1);
        }
    }
    
    return dp[v];
}

void solve() {
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) dp[i] = -1;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[--y].push_back(--x);
    }
    
    for (int i = 0; i < n; i++) {
        ans = max(ans, dfs(i));
    }
    
    cout << ans;
}



int main() {
    freopen("longpath.in", "rt", stdin);
    freopen("longpath.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
