#include <iostream>
#include <queue>
using namespace std;

typedef struct Point {
    int x;
    int y;

}Point;

const Point p[4] = { {1,0},{0,1},{-1,0},{0,-1} };

string board[1000];
int ans[1000][1000];
bool visited[1000][1000];
int n, m;

void travel(int x, int y) {
    if (board[y][x] == '1') return;
    if (visited[y][x]) return;
    bool tempVisited[1000][1000]{};
    queue<Point> q;
    vector<Point> v;
    int area = 1;
    q.push({ x,y });
    visited[y][x] = true;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Point current = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int px = current.x + p[k].x;
                int py = current.y + p[k].y;
                if (px < 0 || px >= m) continue;
                if (py < 0 || py >= n) continue;
                if (visited[py][px]) continue;

                if (board[py][px] == '1') {
                    v.push_back({ px,py });
                    continue;
                }
                
                visited[py][px] = true;
                q.push({ px,py });
                area++;
            }
        }
    }
    for (Point one : v) {
        if (tempVisited[one.y][one.x]) continue;
        ans[one.y][one.x] += area;
        tempVisited[one.y][one.x] = true;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            travel(j, i);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '0') { cout << "0"; continue; }
            cout << (ans[i][j] + 1) % 10;
        }
        cout << endl;
    }

}