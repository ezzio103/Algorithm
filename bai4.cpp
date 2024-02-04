#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    // Đọc các khoảng thời gian và lưu vào một vector
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        intervals.push_back(make_pair(a, b));
    }

    // Sắp xếp các khoảng thời gian theo thứ tự tăng dần của thời gian kết thúc
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int non_overlapping_count = 1;
    int end_time = intervals[0].second;

    // Duyệt qua các khoảng thời gian và chọn các khoảng không giao nhau
    for (int i = 1; i < n; ++i) {
        if (intervals[i].first > end_time) {
            ++non_overlapping_count;
            end_time = intervals[i].second;
        }
    }

    // In ra số lượng khoảng thời gian trong tập con lớn nhất
    cout << non_overlapping_count << endl;

    return 0;
}

