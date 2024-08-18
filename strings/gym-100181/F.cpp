#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const long long INF = 1e16;

const long long MOD = 1e9 + 7;
const long long POW = 31;

long long k_hash[MAXN];

void precalc() {
    k_hash[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        k_hash[i] = (k_hash[i - 1] * POW) % MOD;
    }
}

vector<long long> hash_calc(const string &s) {
    vector<long long> hash(s.size() + 1);
    for (int i = 1; i <= s.size(); i++) {
        hash[i] = (hash[i - 1] * POW + (s[i - 1] - 'a' + 1)) % MOD;
    }
    return hash;
}

long long get_hash(const vector<long long> &hash, int l, int r) {
    long long ans = (hash[r] - hash[l - 1] * k_hash[r - l + 1]) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}




void solve() {
    string s;
    cin >> s;
    
    precalc();
    vector<long long> hash = hash_calc(s);
    int q;
    cin >> q;
    
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c) {
            swap(a, c);
            swap(b, d);
        }
        if (get_hash(hash, a, b) == get_hash(hash, c, d)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("substrcmp.in", "rt", stdin);
    freopen("substrcmp.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
