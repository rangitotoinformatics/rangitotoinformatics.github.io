#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N, K, B; cin >> N >> K >> B;
    vector<ll> A(K);
    for (ll i = 0; i < K; i++) cin >> A[i];
    vector<ll> broken(N + 1, 0);
    for (ll i = 0; i < B; i++) {
        ll C; cin >> C;
        broken[C] = 1;
    }
    const ll MOD = 1000000007;
    vector<ll> dp(N + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= N; i++) {
        if (broken[i]) continue;
        for (ll a : A) {
            if (a <= i) dp[i] = (dp[i] + dp[i - a]) % MOD;
        }
    }
    cout << dp[N] << "\n";
}
