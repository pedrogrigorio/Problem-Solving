//Problem reference: https://practice.geeksforgeeks.org/problems/reverse-squared-sum/0

#include <stdio.h>

int reverseSquaredSum(int array[], int n){
    int result = array[n-1]*array[n-1];
    bool signal = true;

    for(int i = n-2; i >= 0; i--){
        if(signal){
            result -= array[i]*array[i];
            signal = false;
        }
        else{
            result += array[i]*array[i];
            signal = true;
        }
    }

    return result;
}

int main(){

    int t;
    scanf("%d", &t);

    int result[t];

    int n;
    for(int i = 0; i < t; i++){

        scanf("%d", &n);
        int array[n];

        for(int i = 0; i < n; i++){
            scanf("%d", &array[i]);
        }

        result[i] = reverseSquaredSum(array, n);
    }

    for(int i = 0; i < t; i++)
        printf("result: %d\n", result[i]);
}