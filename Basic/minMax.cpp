#include <iostream>
#include <vector>
#include <limits.h>

std::vector<int> minMax(std::vector<int> array, int n){

    int min = INT_MAX;
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(array[i] < min)
            min = array[i];
        if(array[i] > max)
            max = array[i];
    }
    
    std::vector<int> result;
    result.push_back(min);
    result.push_back(max);

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

    std::vector<int> result;
    result = minMax(array, n);

    printf("Minimum element is: %d\n Maximum element is: %d", result[0], result[1]);
}