#include <string>
#include <vector>
#include <set>

using namespace std;

vector<char> num;
vector<bool> visited;
set<int> primeNumbers;
int answer = 0;
string tempNumber = "";

bool primeNumber(int number) {
    if (number == 0 || number == 1) return false;
    else if (number == 2) return true;
    for (int i = 2; i < number; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

void search(int index) {
    visited[index] = true;
    tempNumber += num.at(index);
    bool isPrime = (tempNumber.size() <= 1) ? primeNumber(num.at(index) - '0') : primeNumber(stoi(tempNumber));
    if (isPrime) primeNumbers.insert(stoi(tempNumber));
    
    for (int i = 0; i < num.size(); i++) {
        if (visited[i]) continue;
        search(i);
    }
    
    visited[index] = false;
    tempNumber.erase(tempNumber.size() - 1);
}

int solution(string numbers) {
    
    for (int i = 0; i < numbers.size(); i++) {
        num.push_back(numbers[i]);
        visited.push_back(false);
    }
    
    for (int i = 0; i < num.size(); i++) {
        search(i);
    }
    
    answer = primeNumbers.size();

    return answer;
}