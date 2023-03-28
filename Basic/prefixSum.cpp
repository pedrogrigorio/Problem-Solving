#include <iostream>
#include <vector>

std::vector<int> prefixSum(std::vector<int> array, int n){
    std::vector<int> result;
    result.push_back(array[0]);
    for(int i = 1; i < n; i++)
        result[i] = array[i] + result[i-1];

    return result;
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

    std::vector<int> result = prefixSum(array, n);
    for(int i = 0; i < n; i++)
        printf("%d ", result[i]);
}