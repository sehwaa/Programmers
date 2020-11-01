#include <string>
#include <vector>

using namespace std;

vector<int> numArray;
int targetNum;
int answer = 0;
int sum = 0;

void dfs(int index) {
    int su;
    if (index <= numArray.size() -1) {
        su = numArray.at(index);
    } else {
        if (sum == targetNum) answer++;
        return;
    }

    for (int i = 0; i < 2; i++) {
        if (i == 1) su *= -1;
        sum += su;
        dfs (index+1); 
        sum -= su;
    }
}

int solution(vector<int> numbers, int target) {
    targetNum = target;
    for (int i = 0; i < numbers.size(); i++) {
        numArray.push_back(numbers.at(i));
    }

    dfs(0);

    return answer;
}