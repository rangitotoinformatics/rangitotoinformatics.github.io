#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N, M; cin >> N >> M;
    vector<string> g(N);
    for (auto &row : g) cin >> row;
    vector<vector<ll>> dp(N, vector<ll>(M, -1));
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < M; j++) {
            if (g[i][j] == '#') continue;
            ll best = -1;
            if (i == 0 && j == 0) best = 0;
            if (i > 0) best = max(best, dp[i-1][j]);
            if (j > 0) best = max(best, dp[i][j-1]);
            if (best != -1) dp[i][j] = best + (g[i][j] - '0');
        }
    }
    cout << dp[N-1][M-1] << '\n';
}