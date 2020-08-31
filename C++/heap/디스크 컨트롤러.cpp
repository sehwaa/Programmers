#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int tSum = 0;
    int watingSum = 0;
    
    priority_queue< int, vector<int>, greater<int> > q;
    priority_queue< int, vector<int>, greater<int> > pq;
    
    for (int i = 0; i < jobs.size(); i++) {
        pq.push(jobs[i][0]);
    }
    
    int first = pq.top();
    vector<int> v;
    for (int i = 0; i < jobs.size(); i++) {
        if (jobs[i][0] == first) {
            v.push_back(jobs[i][1]);
        }
    }
    
    int second;
    if (v.size() > 1) {
        priority_queue< int, vector<int>, greater<int> > temp;
        for (int i = 0; i < v.size(); i++) {
            temp.push(v[i]);
        }
        second = temp.top();
        tSum += first + second;
        answer += first + second;
    } else {
        tSum += first + v[0];
        answer += first + v[0];
    }
    
    for (int i = 0; i < jobs.size(); i++) {
        if (jobs[i][0] == first && jobs[i][1] == second) {
            jobs.erase(jobs.begin() + i);
        }
    }
    
    for (int i = 0; i < jobs.size(); i++) {
        q.push(jobs[i][1]);
    }
    
    while (!q.empty()) {
        int t = q.top();
        q.pop();
        
        for (int i = 0; i < jobs.size(); i++) {
            if (jobs[i][1] == t) {
                tSum += t;
                watingSum = tSum - t - jobs[i][0];
                if (watingSum <= 0) watingSum = 0;
                if (t + watingSum <= 1000) answer += t + watingSum;
                break;
            }
        }
    }
    
    return answer / (jobs.size() + 1);
}