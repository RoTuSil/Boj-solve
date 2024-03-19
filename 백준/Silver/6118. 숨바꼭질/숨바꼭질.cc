#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[20001];
bool visited[20001];

int main() {
    int n, m;
    vector<int> ans;
    int length = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        length++;
        ans.clear();
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int current = q.front();
            q.pop();

            ans.push_back(current);
            for (int k : v[current]) {

                if (!visited[k]) {
                    q.push(k);
                    visited[k] = true;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << " " << length - 1 << " " << ans.size();
}