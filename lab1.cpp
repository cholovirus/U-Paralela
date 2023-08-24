#include <iostream>
#include <random>
#include <chrono>

using namespace std;
#define MAX 500
void firstloop(){
    double A[MAX][MAX], x[MAX], y[MAX];


    //inizializar A y x y= 0;

    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            A[i][j] = i+j;
        }
    }

    for(int i=0;i<MAX;i++) x[i] =i; 
    for(int i=0;i<MAX;i++) y[i] =0; 

    auto start = std::chrono::high_resolution_clock::now();
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            y[i] += A[i][j]*x[j];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tiempo de ejecución: " << duration.count() << " sec" << std::endl;
    
}
void secondloop(){
    double A[MAX][MAX], x[MAX], y[MAX];

    //asignar y= 0;
    for(int i=0;i<MAX;i++) y[i] =0; 


    auto start = std::chrono::high_resolution_clock::now();
    for(int j=0;j<MAX;j++){
        for(int i=0;i<MAX;i++){
            y[i] += A[i][j]*x[j];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Tiempo de ejecución: " << duration.count() << " sec" << std::endl;
}

int main(){
   
    
    cout<<"Primer Loop"<<endl;firstloop();
    cout<<"Segundo Loop"<<endl;secondloop();
    
    return 0;
}