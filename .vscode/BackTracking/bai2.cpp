#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int findMinDifference(const vector<int>& bags) {
    int totalSum = 0;
    for (int value : bags) {
        totalSum += value;
    }

    int n = bags.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (bags[i - 1] <= j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - bags[i - 1]];
            }
        }
    }

    int minDiff = INT_MAX;
    for (int j = totalSum / 2; j >= 0; j--) {
        if (dp[n][j]) {
            minDiff = totalSum - 2 * j;
            break;
        }
    }

    return minDiff;
}

int main() {
    int n;
    cin >> n;

    vector<int> bags(n);
    for (int i = 0; i < n; i++) {
        cin >> bags[i];
    }

    cout << findMinDifference(bags) << endl;

    return 0;
}
