#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

Matrix prefixMatrixSum(Matrix mat){
    Matrix result = mat;
    for(int i = 0; i < mat.size(); i++){
        for(int j = 0; j < mat[0].size(); j++){
            if(i == 0 && j == 0){
                result[i][j] = mat[i][j];
            }
            else if(i == 0){
                result[i][j] = result[i][j-1] + result[i][j];
            }
            else if(j == 0){
                result[i][j] = result[i-1][j] + result[i][j];
            }
            else{
                result[i][j] += result[i][j-1] + result[i-1][j] - result[i-1][j-1];
            }
        }
    }
    return result;
}

int main(){
    Matrix matrix;
    int rows {0};
    int columns {0};

    std:: cin >> rows;
    std:: cin >> columns;

    int val = 0;
    for(int i = 0; i < rows; i++){
        std::vector<int> row;
        for(int j = 0; j < columns; j++){
            std::cin >> val;
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    Matrix result = prefixMatrixSum(matrix);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[0].size(); j++){
            std::cout << result[i][j] << " ";
        }
        std::cout << "\n";
    }
}