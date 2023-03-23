#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::unordered_map<int, int> countFreq(std::vector<int> array, int n){
    std::unordered_map<int, int> umap;
    for(int i = 0; i < n; i++)
        umap[array[i]]++;
    
    return umap;
}

int main(){

    int n = 0;
    scanf("%d", &n);

    std::vector<int> array;
    for(int i = 0; i < n; i++){
        int val = 0;
        scanf("%d", &val);
        array.push_back(val);
    }

    std::unordered_map<int, int> result = countFreq(array, n);

    for (auto pair : result) {
        std::cout << pair.first << " " << pair.second << "\n";
    }
}