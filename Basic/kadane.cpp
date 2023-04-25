#include <iostream>
#include <vector>
#include <limits.h>

int kadane(std::vector<int> array) {

    int max_so_far = INT_MIN;
    int max_ending_here = 0;

    for(int val : array) {
        max_ending_here += val;

        if(max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
        }

        if(max_ending_here < 0) {
            max_ending_here = 0;
        }
    }

    return max_so_far;
}

int main() {

    std::vector<int> array;
    int n {0};
    int val {0};

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> val;
        array.push_back(val);
    }

    int result = kadane(array);

    std::cout << result;
}