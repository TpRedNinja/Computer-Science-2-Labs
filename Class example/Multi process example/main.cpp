#include <iostream>
using namespace std;
int main()
{
    // Sizes of matrices
    const int SQUARE = 6;
    const int SIZE = SQUARE * SQUARE;
    // srand for seed
    srand(202);
    // Declare 2 square matrices of constant size
    int matrix_a[SIZE][SIZE];
    int matrix_b[SIZE][SIZE];
    int result_matrix[SIZE][SIZE] = {0};
    // Randomly generate 2 matrices that are square
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            matrix_a[i][j] = rand() % 101;
            matrix_b[i][j] = rand() % 101;
        }
    }
    // Print a
    cout << "MATRIX A:" << endl;
    for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++){
    cout << matrix_a[i][j] << " ";
    }
    cout << endl;
    }
    cout << endl;
    // Print b
    cout << "MATRIX B:" << endl;
    for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++){
    cout << matrix_b[i][j] << " ";
    }
    cout << endl;
    }
    cout << endl;
    int block_num;
    cout << "What result block number would you like to populate: ";
    cin >> block_num;
    // two D arrays made
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (i/SQUARE == block_num/SQUARE && j/SQUARE == (block_num % SQUARE)){
                for (int k = 0; k < SIZE; k++){
                    result_matrix[i][j] += matrix_a[i][k] * matrix_b[k][j];
                }
            }
        }
    }
    // Print out matrix
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cout <<result_matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}