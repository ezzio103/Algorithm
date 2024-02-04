#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector<int> arr(1000);
vector<int> dp(1000, 0);
int max_subsequence_sum(int n) {
    if (n == 0) {
        return arr[0];
    }
    if (n==1)
    {
        return max(arr[0], arr[1]);
    }
    dp[n] =  max(max_subsequence_sum(n-1),(max_subsequence_sum(n-2)+arr[n]));
    return dp[n];
}

int main() {
      cin >> n; 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << max_subsequence_sum(n-1) << endl;
    return 0;
}
