#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e4 + 10;
const int INF = 1e9;


long long manacher_odd(string s) {
    int n = (int) s.size();
    vector<int> d(n, 1);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r)
            d[i] = min(r - i + 1, d[l + r - i]);
        while (i - d[i] >= 0 && i + d[i] < n && s[i - d[i]] == s[i + d[i]])
            d[i]++;
        if (i + d[i] - 1 > r)
            l = i - d[i] + 1, r = i + d[i] - 1;
    }
    long long ans = 0;
    for (auto el: d) ans += el;
    return ans;
}

long long manacher_even(string s) {
    int n = (int) s.size();
    vector<int> d(n, 0);
    int l = -1, r = -1;
    for (int i = 0; i < n - 1; i++) {
        if (i < r)
            d[i] = min(r - i, d[l + r - i - 1]);
        while (i - d[i] >= 0 && i + d[i] + 1 < n && s[i - d[i]] == s[i + d[i] + 1])
            d[i]++;
        if (i + d[i] > r)
            l = i - d[i] + 1, r = i + d[i];
    }
    long long ans = 0;
    for (auto el: d) ans += el;
    return ans;
}

long long pal_cnt(string s) {
    return manacher_odd(s) + manacher_even(s);
}

void solve() {
    string s;
    cin >> s;
    cout << pal_cnt(s) - s.size();
}



int main() {
    freopen("palindrome.in", "rt", stdin);
    freopen("palindrome.out", "wt", stdout);
    //precalc();
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
