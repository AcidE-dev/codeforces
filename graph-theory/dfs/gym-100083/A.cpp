#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;

vector<int> g[MAXN];
int tin[MAXN], tout[MAXN];
int n, t;

void dfs(int v) {
    tin[v] = t++;
    for (int u: g[v]) {
        if (!tin[u]) dfs(u);
    }
    tout[v] = t++;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        g[x].push_back(i + 1);
    }
    dfs(0);
    
    int m;
    cin >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (tin[x] < tin[y] && tout[x] > tout[y]) cout << 1 << endl;
        else cout << 0 << endl;
    }
}

int main() {
    freopen("ancestor.in", "rt", stdin);
    freopen("ancestor.out", "wt", stdout);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
