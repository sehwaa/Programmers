#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<char> numberArray;
bool visited[8];
int count = 0;
string add = "";

bool primeNumber(int su) {
    if (su == 0 || su == 1) return false;
    for (int i = 2; i < su; i++) {
        if (su % i == 0) return false;
    }
    return true;
}

void make(int index) {
    char su = numberArray[index];
    visited[index] = true;
    
    if (add == ""){
        if (su - '0' == 0) return;
        if (primeNumber(su-'0')) count++;
        add += su;
    } else {
        add += su;
        if (primeNumber(stoi(add))) count++;
        else add.erase(add.size()-1);
    }
    
    cout << add << endl;
    if (index == numberArray.size() - 1) return;
    
    for (int i = 0; i < numberArray.size(); i++) {
        if (i == index || visited[i]) continue;
        make(i);
        visited[i] = false;
        add.erase(add.size()-1);
    }  
}

int solution(string numbers) {
    
    for (int i = 0; i < numbers.size(); i++) {
        numberArray.push_back(numbers[i]);
        visited[i] = false;
    }
    
    for (int i = 0; i < numberArray.size(); i++) {
        make(i);
    }
    int answer = count;
    return answer;
}