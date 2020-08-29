#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> q;

    for (int i = 0; i < operations.size(); i++) {
        if (operations.at(i) == "D 1" && q.size() > 0) {
            sort(q.begin(), q.end());
            q.pop_back();
        } else if (operations.at(i) == "D -1" && q.size() > 0) {
            sort(q.begin(), q.end());
            q.pop_front();
        } else if (operations.at(i).substr(0,1) == "I") {
            q.push_back(stoi(operations.at(i).substr(2)));
        }
    }

    if (q.empty()) {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    } else {
        sort(q.begin(), q.end());
        answer.push_back(q.back());
        answer.push_back(q.front());
        return answer;
    }
}