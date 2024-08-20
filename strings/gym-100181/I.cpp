#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e6 + 10;
const long long INF = 1e16;

const long long MOD = 1e9 + 7;
const long long POW = 31;

long long k_hash[MAXN], _hash[MAXN];

int n, ans;

void precalc() {
    k_hash[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        k_hash[i] = (k_hash[i - 1] * POW) % MOD;
    }
    
    
}

void hash_calc(const string &s) {
    _hash[0] = 0;
    for (int i = 1; i <= s.size(); i++) {
        _hash[i] = (_hash[i - 1] * POW + (s[i - 1] - 'a' + 1)) % MOD;
    }
}

long long get_hash(int l, int r) {
    long long ans = (_hash[r] - _hash[l - 1] * k_hash[r - l + 1]) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}




void solve() {
    string s, t;
    cin >> s;
    n = s.size();
    t = s + s;
    ans = 1;
    hash_calc(t);
    for (int i = 2; i <= n; i++) {
        int l = 1, r = n, m;
        while (l <= r) {
            m = (l + r) / 2;
            if (get_hash(1, m) == get_hash(i, i + m - 1)) l = m + 1;
            else r = m - 1;
        }
        if (l == n) continue;
        ans += (t[r] > t[r + i - 1]);
        //cout << r << ' ';
    }
    cout << ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cyclic.in", "rt", stdin);
    freopen("cyclic.out", "wt", stdout);
    precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
