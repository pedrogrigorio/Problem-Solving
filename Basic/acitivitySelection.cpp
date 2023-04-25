#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using Pair = std::pair<int, int>;
using Dict = std::vector<Pair>;

std::vector<int> activitySelection(std::vector<int> start, std::vector<int> end) {

    std::vector<int> activities;
    Dict dict;

    for (int i = 0; i < end.size(); i++) {
        Pair pair;
        pair.first = i;
        pair.second = end[i];
        dict.push_back(pair);
    }

    std::sort(dict.begin(), dict.end(), [](Pair a, Pair b){ return a.second < b.second;});

    activities.push_back(dict[0].first);
    for (int i = 0; i < end.size(); i++) {
        if (start[i] >= dict[activities.back()].second) {
            activities.push_back(i);
        }
    }

    return activities;
}

int main() {
    
    std::vector<int> start;
    std::vector<int> end;
    std::vector<int> result;

    int n {0};
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        int val {0};
        std::cin >> val;
        start.push_back(val);
    }

    for (int i = 0; i < n; i++) {
        int val {0};
        std::cin >> val;
        end.push_back(val);
    }

    result = activitySelection(start, end);

    for (int val : result) {
        std::cout << val << " ";
    }

}