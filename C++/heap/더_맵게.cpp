#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int min = 0;
    int secondMin = 0;
    int answer = 0;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville.at(i));
    }

    if (pq.top() >= K) return -1;

    while (!pq.empty()) {
        answer++;

        if (pq.size() <= 1) {
            answer = 0;
            break;
        }

        min = pq.top();
        pq.pop();
        secondMin = pq.top();
        pq.pop();

        int newScoville = min + (2 * secondMin);

        if (pq.size() == 0 && newScoville >= K) break;
        else if (pq.top() >= K && newScoville >= pq.top()) break;
        else pq.push(newScoville);
    }

    if (answer == 0) answer = -1;

    return answer;
}