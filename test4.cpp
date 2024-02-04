#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
vector<int> filterInRange(const int arr[], int size, int min, int max)
{
    vector<int> result;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= min && arr[i] <= max)
        {

            result.push_back(arr[i]); // Thêm vào vector nếu phần tử nằm trong khoảng
        }
    }
    return result;
}
int sumOfVector(const vector<int> &vec)
{
    int sum = 0;
    for (int element : vec)
    {
        sum += element; // Cộng dồn từng phần tử vào tổng
    }
    return sum;
}
int main()
{
    int n;
    int maxx;
    int count = 0;
    int minn;
    cin >> n >> minn >> maxx;
    int a[n + 10000];
    int a1, a2;
    int sum[n + 10000] = {0};
    bool check = true;
    vector<int> arr;
    for (int i = 10000; i < 10000 + n; i++)
    {
        cin >> a[i];
    }
    for (int i = 10000; i < 10000 + n; i++)
    {
        sum[i] = a[i];
        for (int j = i - maxx; j <= i - minn; j++)
        {
            if (sum[j] > count)
                count = sum[j];
        }
        sum[i] += count;
        count = 0;
    }
    for (int i = 10000; i < 10000 + n; i++)
    {
        if (sum[i] > count)
            count = sum[i];
    }
    cout << count;
}