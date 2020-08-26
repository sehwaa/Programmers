#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue< int, vector<int>, greater<int> > pq;
    
   for (int i = 0; i < operations.size(); i++) {
       if (operations.at(i) == "D 1") {

       } else if (operations.at(i) == "D -1") {
           
       } else {
           
       }
   }
    return answer;
}