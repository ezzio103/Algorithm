#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long count = 0;
    unordered_map<int, int> sumCount;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            sumCount[a[i] + a[j]]++;
        }
    }

    for (int k = 0; k < n; ++k) {
        if (sumCount.find(a[k]) != sumCount.end()) {
            count = (count + sumCount[a[k]]) % MOD;
        }
    }

    cout << count << endl;
    return 0;
}
