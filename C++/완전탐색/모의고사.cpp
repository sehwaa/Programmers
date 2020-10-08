#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int supoza1[5] = {1,2,3,4,5};
int supoza2[8] = {2,1,2,3,2,4,2,5};
int supoza3[10] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> count = {0, 0, 0};
    for (int i = 0; i < answers.size(); i++) {
        
        if (answers.at(i) == supoza1[i%5]) count[0] += 1;
        if (answers.at(i) == supoza2[i%8]) count[1] += 1;
        if (answers.at(i) == supoza3[i%10]) count[2] += 1;
    }
    
    int max = *max_element(count.begin(), count.end());
    for (int i = 0; i < 3; i++) {
        if (count[i] == max) answer.push_back(i+1);
    }
    return answer;
}