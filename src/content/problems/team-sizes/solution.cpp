#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    ll N; cin >> N;
    vector<vector<ll>> adj(N + 1);
    for (ll i = 0; i < N - 1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll> parent(N + 1, -1), order;
    queue<ll> q;
    parent[1] = 0;
    q.push(1);
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        order.push_back(u);
        for (ll v : adj[u]) {
            if (parent[v] != -1) continue;
            parent[v] = u;
            q.push(v);
        }
    }
    vector<ll> sz(N + 1, 1);
    for (ll i = (ll)order.size() - 1; i > 0; i--) {
        ll u = order[i];
        sz[parent[u]] += sz[u];
    }
    for (ll i = 1; i <= N; i++) cout << sz[i] << " \n"[i == N];
}
