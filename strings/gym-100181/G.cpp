#include <bits/stdc++.h>

using namespace std;

int n;

void solve() {
    cin >> n;
    vector<int> z(n), p(n);
    for (auto &el: z) cin >> el;
    
    for (int i = 1; i < n; i++) {
        if (z[i]) {
            for (int j = z[i] - 1; j >= 0 && !p[i + j]; j--) {
                p[i + j] = j + 1; 
            }
        }
    }
    
    for (auto el: p) cout << el << ' ';
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("trans.in", "rt", stdin);
    freopen("trans.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
