#include <string>
#include <vector>

using namespace std;

vector<vector<string>> allTickets;
vector<bool> visited;
vector<string> answer;

void dfs(string airportName) {
    answer.push_back(airportName);
    
    string next = "";
    int index = 0;
    for (int i = 0; i < allTickets.size(); i++) {
        if (allTickets[i][0] == airportName && !visited[i]) {
            if (!next.empty() && stoi(allTickets[i][1]) < stoi(next) || next.empty()) next = allTickets[i][1]; index = i;
        }
    }
    
    if (!next.empty()) {
        visited[index] = true;
        dfs(next);
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    allTickets = tickets;
    dfs("ICN");
    
    return answer;
}