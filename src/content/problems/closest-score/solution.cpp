#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> s(n);
    for (int &v : s) cin >> v;
    sort(s.begin(), s.end());
    while (q--) {
        int x;
        cin >> x;
        auto it = lower_bound(s.begin(), s.end(), x);
        cout << (it == s.end() ? -1 : *it) << '\n';
    }
}
