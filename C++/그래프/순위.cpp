#include <string>
#include <vector>

using namespace std;

#define MAX 101

bool visited[MAX][MAX];
vector<vector<int>> r;
int vNode;

void recursive(int num) {
    if (!visited[vNode][num]) {
        visited[vNode][num] = true;
        visited[num][vNode] = true;
    }
    else return;
    
    for (int i = 0; i < r.size(); i++) {
        if (r[i][0] == num) {
            recursive(r[i][1]);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    r = results;
    
    for (int i = 1; i <= n; i++) {
        vNode = i;
        recursive(i);
    }
    
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (visited[i][j]) cnt++;
        }
        if (cnt == n) answer++;
    }
    return answer;
}