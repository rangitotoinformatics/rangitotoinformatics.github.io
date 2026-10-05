## Model solution

```cpp
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 1677;

int N;
vector<long long> grade;
int main() {
    cin >> N;
    grade.resize(N+1, -1);
    grade[1] = 6, grade[2] = 7;
    for(int n = 3; n <= N; n++) {
        grade[n] = grade[n-1] * grade[n-2] % MOD;
    }
    cout << max_element(grade.begin(), grade.end()) - grade.begin();
}
```
