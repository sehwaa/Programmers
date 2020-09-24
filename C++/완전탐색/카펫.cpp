#include <string>
#include <vector>

using namespace std;

#define corner 4
vector<int> factor;
vector<int> answer;

void allGrid (int brown, int yellow) {
    for (int i = 1; i <= yellow; i++) {
        if (i * i > yellow) break;
        if (yellow % i == 0) factor.push_back(i);
    }
    
    for (int i = 0; i < factor.size(); i++) {
        int vertical = factor[i];
        int horizontal = yellow / vertical;
        
        int grid = vertical * 2 + horizontal * 2 + corner;
        if (grid == brown) {
            answer.push_back(horizontal + 2);
            answer.push_back(vertical + 2);
        }
    }
}

vector<int> solution(int brown, int yellow) {
    allGrid(brown, yellow);
    return answer;
}