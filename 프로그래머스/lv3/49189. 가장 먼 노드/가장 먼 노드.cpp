#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int nodeCountBefore = 0;
    vector<int> graph[20001];
    queue<int> q;
    bool visited[20001]{};
    for(int i = 0;i<edge.size();i++) {
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    visited[1] = true;
    while(!q.empty()) {
        int nodeCountCurrent = 0;
        bool hasFurther = false;
        int size = q.size();
        for(int i = 0;i < size; i++) {
            int now = q.front();
            q.pop();
            for(int j = 0; j < graph[now].size(); j++) {
                if(!visited[graph[now][j]]) {
                    q.push(graph[now][j]);
                    visited[graph[now][j]] = true;
                    hasFurther = true;
                    nodeCountCurrent++;
                }
            }
        }
        if(hasFurther)nodeCountBefore = nodeCountCurrent;
    }
    return nodeCountBefore;
}