#include <string>
#include <vector>

using namespace std;

#define MAX 201
int answer = 0;
int allComputers[MAX][MAX];
bool visited[MAX][MAX];
int ComputerCnt = 0;

void dfs(int index) {
    for (int i = 0; i < ComputerCnt; i++) {
        if (i == index) continue;
        if (!visited[index][i] &&  allComputers[index][i] == 1) {
            visited[index][i] = true;
            visited[i][index] = true;
            answer++;
            dfs(i);
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
        dfs(i);
    }
    return answer;
}