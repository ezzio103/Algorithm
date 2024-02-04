#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
    int x, y, steps;
};

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }

    // Dịch chuyển theo 4 hướng: lên, xuống, trái, phải
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    // Sử dụng BFS để tìm đường ngắn nhất
    queue<Point> q;
    q.push({r - 1, c - 1, 0});
    maze[r - 1][c - 1] = 1; // Đánh dấu ô xuất phát đã được đi qua
    while (!q.empty()) {
        Point curr = q.front();
        q.pop();
        if (curr.x == 0 || curr.x == n - 1 || curr.y == 0 || curr.y == m - 1) {
            // Nếu đến biên của mê cung, in số bước và kết thúc chương trình
            cout << curr.steps +1 << endl;
            return 0;
        }
        // Duyệt qua 4 hướng
        for (int i = 0; i < 4; ++i) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY] == 0) {
                // Nếu ô mới là ô trống, đi đến ô đó và đánh dấu đã đi qua
                q.push({newX, newY, curr.steps + 1});
                maze[newX][newY] = 1;
            }
        }
    }

    // Nếu không tìm thấy đường đi đến biên, in -1
    cout << -1 << endl;

    return 0;
}
