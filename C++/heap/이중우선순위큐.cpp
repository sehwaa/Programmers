#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int max_pivot = 0;
    int min_pivot = 0;
    priority_queue< int, vector<int> > pq;
    
    for (int i = 0; i < operations.size(); i++) {
        if (operations.at(i) == "D 1") {
            max_pivot++;
        } else if (operations.at(i) == "D -1") {
            min_pivot++;
        } else {
            pq.push(atoi(operations.at(i).replace(0,2,"").c_str()));
        }
    }

    int max;
    for (int i = 0; i < max_pivot; i++) {
        if (!pq.empty()) {
            max = pq.top();
            pq.pop();
        }
    }
    
    int min;
    int left_size = pq.size() - min_pivot;
    for (int i = 0; i < left_size; i++) {
        if (!pq.empty()) {
            min = pq.top();
            pq.pop();
        }
    }
    
    answer.push_back(max);
    answer.push_back(min);
    
    return answer;
}