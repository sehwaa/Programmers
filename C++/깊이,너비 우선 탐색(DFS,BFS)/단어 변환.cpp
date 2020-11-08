#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 51
vector<int> v[MAX];
vector<int> visited;
int answer = 0;

int bfs(int index, int targetIndex) {
    queue<int> q;
    q.push(index);
    visited[index] = 1;

    while(!q.empty()) {
        int start = q.front();
        q.pop();

        if (start == targetIndex) return visited[start] - 1;
        for (int i = 0; i < v[start].size(); i++) {
            if (visited[v[start][i]] == 0) {
                visited[v[start][i]] = visited[start] + 1;
                q.push(v[start][i]);
            }
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int targetIndex = -1;
    words.push_back(begin);
    for (int i = 0; i < words.size(); i++) {
        visited.push_back(0);
        if (words[i] == target) targetIndex = i;
        for (int j = i+1; j < words.size(); j++) {
            int canChangeCount = 0;
            for (int k = 0; k < words[i].size(); k++) {
                if (words[i].at(k) != words[j].at(k)) canChangeCount++;
            }
            if (canChangeCount < 2) {
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    }

    words.pop_back();

    if (targetIndex == -1) return 0;
    else answer = bfs(words.size(), targetIndex);
    return answer;
}