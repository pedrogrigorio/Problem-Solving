// Problem reference: https://www.geeksforgeeks.org/program-find-sum-elements-given-array/

#include <iostream>
#include <vector>

int sumArray(std::vector<int> array, int n){

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += array[i];
    }

    return sum; 
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

    int sum = sumArray(array, n);

    printf("%d", sum);
}