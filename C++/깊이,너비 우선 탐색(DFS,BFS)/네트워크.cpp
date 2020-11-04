#include <string>
#include <vector>

using namespace std;

#define MAX 201
int answer = 0;
int allComputers[MAX][MAX];
bool visited[MAX][MAX];
int ComputerCnt = 0;
int count = 0;

void dfs(int index) {
    count++;
    for (int i = 0; i < ComputerCnt; i++) {
        if (i == index) continue;
        if (allComputers[index][i] == 1) {
            if (!visited[index][i]) {
               visited[index][i] = true;
               visited[i][index] = true; 
                count++;
                dfs(i);
            } else {
                count -= 1;
            }
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
        if (count >= 1) {
            count = 0;
            answer++;
        }
    }
    return answer;
}