#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N, M, P; cin >> N >> M >> P;
    vector<vector<ll>> adj(N + 1);
    for (ll i = 0; i < M; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> dist(N + 1, -1);
    queue<ll> q;
    for (ll i = 0; i < P; i++) {
        ll b; cin >> b;
        dist[b] = 0;
        q.push(b);
    }
    while (!q.empty()) {
        ll v = q.front(); q.pop();
        for (ll u : adj[v]) {
            if (dist[u] != -1) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
    for (ll i = 1; i <= N; i++) cout << dist[i] << " \n"[i == N];
}