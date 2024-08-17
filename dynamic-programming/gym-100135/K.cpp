#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4 + 10;
const int INF = 1e9;

long long n, m, ans;

void solve() {
    cin >> n >> m;
    
    ans = 1;
    for(int i = 1 ; i <= n;  i++) {
        ans = (ans + m) % i;
    }
    
    cout << ans + 1;
}



int main() {
    freopen("joseph.in", "rt", stdin);
    freopen("joseph.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
