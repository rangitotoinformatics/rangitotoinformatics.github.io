#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N, M, S; cin >> N >> M >> S;
    vector<vector<ll>> adj(N + 1);
    for (ll i = 0; i < M; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> visited(N + 1, 0);
    visited[S] = 1;
    for (ll u : adj[S]) visited[u] = 1;
    for (ll u : adj[S]) {
        for (ll v : adj[u]) visited[v] = 1;
    }
    ll answer = 0;
    for (ll i = 1; i <= N; i++) answer += visited[i];
    cout << answer << "\n";
}
