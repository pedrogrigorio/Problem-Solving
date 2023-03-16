// Problem reference: 

#include <stdio.h>
#include <string>
#include <iostream>

std::string isPalindrome(std::string word){
    std::string response = "Yes";
    for(int i = 0, j = word.length()-1; i < word.length()/2; i++, j--){
        if(word[i] != word[j]){
            response = "No";
        }
    }
    return response;
}

int main(){

    std::string response = isPalindrome("ABCD");
    printf("Response: %s", response.c_str());
}