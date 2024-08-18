#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
const long long INF = 1e16;

const long long MOD = 1e9 + 7;
const long long POW = 31;

long long k_hash[MAXN];
vector<string> s;
vector<vector<long long>> _hash;
string ans;
int n, _min;

void precalc() {
    k_hash[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        k_hash[i] = (k_hash[i - 1] * POW) % MOD;
    }
    
    
}

vector<long long> hash_calc(const string &s) {
    vector<long long> res(s.size() + 1);
    for (int i = 1; i <= s.size(); i++) {
        res[i] = (res[i - 1] * POW + (s[i - 1] - 'a' + 1)) % MOD;
    }
    return res;
}

long long get_hash(const vector<long long> &_hash, int l, int r) {
    long long ans = (_hash[r] - _hash[l - 1] * k_hash[r - l + 1]) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}


bool bs(int k) {
    map<long long, int> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].size() - k + 1; j++) {
            if (cnt[get_hash(_hash[i], j + 1, j + k)] == i) {
                cnt[get_hash(_hash[i], j + 1, j + k)] = i + 1;
                if (i == n - 1) {
                    ans = s[i].substr(j, k);
                    return true;
                }
            }
        }
    }
    return false;
}


void solve() {
    cin >> n;
    s.resize(n);
    _hash.resize(n);
    
    precalc();
    
    _min = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i].size() < _min) _min = s[i].size();
    }
    
    for (int i = 0; i < n; i++) _hash[i] = hash_calc(s[i]);
    
    int l = 0, r = _min + 1;
    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (bs(m)) l = m;
        else r = m;
    }
    cout << ans;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("substr3.in", "rt", stdin);
    freopen("substr3.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
