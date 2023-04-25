// Problem reference: https://www.geeksforgeeks.org/convert-an-array-to-reduced-form-using-hashing/

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> coordinateCompression(std::vector<int> array) {

    std::vector<int> tmp = array;
    std::sort(tmp.begin(), tmp.end());

    std::unordered_map<int, int> umap;
    for (int i = 0; i < tmp.size(); i++) {
        umap[tmp[i]] = i;
    }

    for (int i = 0; i < array.size(); i++) {
        array[i] = umap[array[i]];
    }

    return array;
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

    std::vector<int> result = coordinateCompression(array);

    for (int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
}