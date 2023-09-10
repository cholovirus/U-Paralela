#include <iostream>
#include <vector>
#include <chrono>
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
    vector<vector<float>> matriz(fil, vector<float>(col, 0));


    
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++) {
            matriz[i][j] = rand() % 100; 
        }
    }
    return matriz;
 }

int main(){
	
    int test;
    cout<<"Colocar, 0 multiplicacion clasica, 1 multiplicacion bloques:";
    cin>>test;
    int temp,filA,colB;
    cout<<"Numero de columnas matrixA y filas matrix B:";
    cin>>temp;	
    cout<<"Numero de filas matrixA:";
    cin>>filA;
    cout<<"Numero de columnas matrixB:";
    cin>>colB;
    
    vector<vector<float>> A=matrixGen(filA,temp);
    vector<vector<float>> B=matrixGen(temp,colB);
    
    if (test==0){
    	auto start = std::chrono::high_resolution_clock::now();
    
        vector<vector<float>> res=clasicMultiplicacion(A,B);
    
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Tiempo de ejecución: " << duration.count() << " sec" << std::endl;
    
    }
    
    if (test == 1){
    	auto start1 = std::chrono::high_resolution_clock::now();
    
        vector<vector<float>>  res2 =multiplicacionBloques(A,B,40);
    
        auto end2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration2 = end2 - start1;
        std::cout << "Tiempo de ejecución: " << duration2.count() << " sec" << std::endl;
    
    }
   	
}
