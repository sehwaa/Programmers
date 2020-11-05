#include <string>
#include <vector>

using namespace std;

#define MAX 201
int answer = 0;
int allComputers[MAX][MAX];
bool visited[MAX][MAX];
int ComputerCnt = 0;

void dfs(int node1, int node2) {
    visited[node1][node2] = true;
    visited[node2][node1] = true;
    
    for (int i = 0; i < ComputerCnt; i++) {
        if (!visited[node2][i] && allComputers[node2][i] == 1) {
            dfs(node2, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    ComputerCnt = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < computers[i].size(); j++) {
            allComputers[i][j] = computers[i][j];
            visited[i][j] = false;
        }
    }
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (!visited[i][j] && allComputers[i][j] == 1) {
                dfs(i, j);
                answer++;
            } else if (allComputers[i][j] == 0) {
                count++;
            }
        }
        
        if (count == n-1) answer++;
    }
    return answer;
}