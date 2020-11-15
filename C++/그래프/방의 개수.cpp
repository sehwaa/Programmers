#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
int direction[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int solution(vector<int> arrows) {
    int answer = 0;
    int x = 0;
    int y = 0;
    v.push_back(make_pair(x,y));
    
    for (auto i : arrows) {
        x += direction[i][0];
        y += direction[i][1];
        vector<pair<int,int>>::iterator it = find(v.begin(), v.end(), make_pair(x,y));
        if (it != v.end()) answer++;
        else v.push_back(make_pair(x, y));
    }
    return answer;
}