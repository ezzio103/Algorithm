#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> arr(1000);
int max_subsequence_sum(int n) {
    if (n == 0) {
        return arr[0];
    }
    if (n==1)
    {
        return max(arr[0], arr[1]);
    }
    int res =  max(max_subsequence_sum(n-1),(max_subsequence_sum(n-2)+arr[n]));
    return res;
}

int main() {
      cin >> n; 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << max_subsequence_sum(n-1) << endl;
    return 0;
}





// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int max_subsequence_sum(int n, vector<int>& arr) {
//     if (n == 1) {
//         return arr[0];
//     }

//     vector<int> dp(n, 0);
//     dp[0] = arr[0];
//     dp[1] = max(arr[0], arr[1]);

//     for (int i = 2; i < n; ++i) {
//         dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
//     }

//     return dp[n-1];
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> arr[i];
//     }

//     int result = max_subsequence_sum(n, arr);
//     cout << result << endl;

//     return 0;
// }
