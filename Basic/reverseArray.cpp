
#include <iostream>
#include <math.h>

using namespace std;

int* reverseArray(int array[], int amount){
  for(int i = 0; i <= amount / 2; i++){
    int temp = array[i];
    array[i] = array[amount - i - 1];
    array[amount - i - 1] = temp;
  }
  return array;
}

int main(){
  int n;
  cin >> n;
  int arr[n];
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  
  int* arrResult = reverseArray(arr, n);
  for(int i = 0; i < n; i++){
    printf("%d ", arrResult[i]);
  }

  return 0;

}