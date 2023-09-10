#include <iostream>
#include <cstdlib>
#include <ctime>

#include <vector>
using namespace std;

vector<vector<float>> clasicMultiplicacion(vector<vector<float>> A,vector<vector<float>> B){

    int filA = A.size();
    int colA = A[0].size();
    int colB = B[0].size();

    vector<vector<float>> result(filA, vector<float>(colB, 0));


    for(int i =0;i<filA;i++){
        for(int z=0;z<colB;z++){
            for(int j = 0;j<colA;j++){
                result[i][z] += A[i][j] * B[j][z];
            }   
        }
    }
    
    

    return result;

}

vector<vector<float>> multiplicacionBloques(vector<vector<float>> A,vector<vector<float>> B, int bloque){
    int filA = A.size();
    int colA = A[0].size();
    int colB = B[0].size();

    vector<vector<float>> result(filA, vector<float>(colB, 0));

    for (int i = 0; i < filA; i+=bloque) {
        for (int j = 0; j< colB; j+=bloque) {
            for (int k= 0; k < colA; k+=bloque) {
                for (int x = i; x < min(i + bloque, filA); x++) { //bloques
                    for (int y = j; y < min(j + bloque, colB); y++) {
                        for (int z = k; z < min(k + bloque, colA); z++) {
                            result[x][y] += A[x][z] * B[z][y];
                        }
                    }
                }
            }
        }
    }

    return result;
}

 vector<vector<float>> matrixGen(int fil , int col){
    vector<vector<int>> matriz(fil, vector<int>(col, 0));


    // Llenar la matriz con números aleatorios
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            matriz[i][j] = rand() % 100; // Números aleatorios entre 0 y 99
        }
    }
    return matriz;
 }

int main(){
    srand(time(0));

    vector<vector<float>> A={{1, 2, 3,4},
                            {4, 5, 6,7},
                            {7, 8, 9,10},
                            {7, 8, 9,10}};
    vector<vector<float>> B={{7, 8,9,10},
                            {9, 10,11,12},
                            {11, 12,13,14},
                            {11, 12,13,14}};
    
    vector<vector<float>> res=clasicMultiplicacion(A,B);
    


     for (const auto& fila : res) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
    
    res=multiplicacionBloques(A,B,3);
    for (const auto& fila : res) {
        for (int elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}
