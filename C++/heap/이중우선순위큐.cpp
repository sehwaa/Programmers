#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue< int, vector<int> > g_pq;
    priority_queue< int, vector<int> > l_pq;
    
    for (int i = 0; i < operations.size(); i++) {
       if (operations.at(i) == "D 1" && g_pq.size() > 1) {
           g_pq.pop();
       } else if (operations.at(i) == "D -1" && l_pq.size() > 1) {
           l_pq.pop();
       } else {
           g_pq.push(atoi(operations.at(i).replace(0,2,"").c_str()));
           l_pq.push(atoi(operations.at(i).replace(0,2,"").c_str()));
       }
    }
    
    // if (pq.size() > 0) {
    //     answer.push_back(g_pq.top());
    //     answer.push_back(l_pq.top());
    // } else {
    //     answer.push_back(0);
    //     answer.push_back(0);
    // }
    
    return answer;
}