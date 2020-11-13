#include <string>
#include <vector>

using namespace std;

vector<vector<string>> allTickets;
vector<bool> visited;
vector<string> answer;
int finalIndex = -1;

int compare(string a, string b) {
	for (int i = 0; i < a.length(); i++) {
		if (a.at(i) - '0' > b.at(i) - '0') return 0;
		else if (a.at(i) - '0' == b.at(i) - '0') continue;
		else return 1;
	}
	
	return 2;
}

void dfs(string airportName) {
   answer.push_back(airportName);
   
   string next = "";
   int index = 0;
   for (int i = 0; i < allTickets.size(); i++) {
      if (allTickets[i][0] == airportName && !visited[i]) {
      	if ((!next.empty() && compare(allTickets[i][1], next) == 1) || next.empty()) {
            bool check = false;
            for (int j = 0; j < allTickets.size(); j++) {
                if (!visited[j] && allTickets[j][0] == allTickets[i][1])    {
                    check = true;
                    break;
                }
            }
            if (check) {
                next = allTickets[i][1];
                index = i;
            } else {
                finalIndex =i;
            }
      	}
      }
   }
   
   if (!next.empty()) {
      visited[index] = true;
      dfs(next);
   }
}

vector<string> solution(vector<vector<string>> tickets) {
   allTickets = tickets;

   for (int i = 0; i < allTickets.size(); i++) {
       visited.push_back(false);
   }
    
   dfs("ICN");
    if (finalIndex != -1) answer.push_back(allTickets[finalIndex][1]);
   
   return answer;
}