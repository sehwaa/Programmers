#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> r;
void findString(string s1, string s2) {
    vector<char> c;
    for (int i = 0; i < s2.size(); i++) {
        for (int j = 0; j < s1.size(); j++) {
            if (s2[i] == s1[j]) {
                c.emplace_back(s1[j]);
            }
        }
    }

    sort(c.begin(), c.end());

    string temp = "";
    for (int i = 0; i < c.size(); i++) {
        temp += c[i];
    }

    if (c.size() > 1) {
        for (int i = 0; i < r.size(); i++) {
            if (r[i] == temp) return;
        }
        r.emplace_back(temp);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (int i = 0; i < orders.size(); i++) {
        for (int j = i+1; j < orders.size(); j++) {
            if (orders.at(i).size() >= orders.at(j).size())
                findString(orders.at(i), orders.at(j));
            else
                findString(orders.at(j), orders.at(i));
        }
    }
    
    // for (int i = 0; i < course.size(); i++) {
    //     for (int j = 0; j < r.size(); j++) {
    //         if (course.at(i) == r.at(j).size()) {
    //             answer.emplace_back(r);
    //         }
    //     }
    // }
    return answer;
}