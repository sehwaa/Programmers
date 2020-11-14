#include <string>
#include <vector>
#include <queue>

#define MAX 20001
using namespace std;

int N;
int visited[MAX];
bool node[MAX][MAX];
int maxEdge = 0;

int bfs(int nodeNum) {
    int answer = 0;
    
    queue<int> q;
    visited[nodeNum] = 1;
    q.push(nodeNum);
    
    while (!q.empty()) {
        int num = q.front();
        q.pop();
        
        for (int i = 1; i <= N; i++) {
            if (node[num][i] && visited[i] == 0) {
                visited[i] = visited[num] + 1;
                if (maxEdge < visited[i]) maxEdge = visited[i];
                q.push(i);
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (visited[i] == maxEdge) answer++;
    }
    
    return answer;
}

int solution(int n, vector<vector<int>> edge) {
    N = n;
    
    for (int i = 0; i < edge.size(); i++) {
        node[edge[i][0]][edge[i][1]] = true;
        node[edge[i][1]][edge[i][0]] = true;
    }
    
    return bfs(1);
}