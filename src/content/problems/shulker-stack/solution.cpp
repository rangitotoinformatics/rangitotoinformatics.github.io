#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<pair<ll,ll>> box(N);
    for (auto &[w, s] : box) cin >> w >> s;
    sort(box.begin(), box.end(), [](const pair<ll,ll> &a, const pair<ll,ll> &b) {
        return a.first + a.second < b.first + b.second;
    });
    ll above = 0, best = LLONG_MIN;
    for (auto &[w, s] : box) {
        best = max(best, above - s);
        above += w;
    }
    cout << best << '\n';
}