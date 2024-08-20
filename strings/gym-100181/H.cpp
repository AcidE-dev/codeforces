#include <bits/stdc++.h>

using namespace std;

int n;

void solve() {
    cin >> n;
    vector<int> z(n), p(n);
    for (auto &el: p) cin >> el;
    
    for (int i = 1; i < n; i++) {
        if (p[i]) {
            z[i - p[i] + 1] = p[i];
        }
    }
    z[0] = n;
    for (int i = 1, j; i < n; i += j) {
            for (j = 1; j < z[i] && min(z[j], z[i] - j) >= z[i + j] ; j++) {
                z[i + j] = min(z[j], z[i] - j);
            }
        }
    
    for (auto el: z) cout << el << ' ';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("invtrans.in", "rt", stdin);
    freopen("invtrans.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
