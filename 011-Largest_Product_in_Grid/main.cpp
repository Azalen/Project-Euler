#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const bool  DEBUG           = false;
const int   PRODUCT_SIZE    = 4;
const int   GRID_SIZE       = 20;

void csvRead(const string & filename, int ** grid){
    ifstream csv_in(filename.c_str());

    for(unsigned int i=0; i<GRID_SIZE; i++){
        for(unsigned int j=0; j<GRID_SIZE; j++){
            csv_in >> grid[i][j];
        }
    }

    csv_in.close();
}

int largestProdInRow(int ** grid){
    int prod = 1;
    // durch Zeilen laufen
    for(int i=0; i<GRID_SIZE; i++){
        // durch Spalte laufen von 0 -> 16
        for(int j=0; j<GRID_SIZE-PRODUCT_SIZE+1;j++){
            int localProduct = 1;
            for(int k=j; k<j+4; k++){
                localProduct *= grid[i][k];
            }
            if(localProduct > prod)
                prod = localProduct;
        }
    }
    return prod;
}

int largestProdInCol(int ** grid){
    int prod = 1;
    // durch Spalten laufen
    for(int j=0; j<GRID_SIZE; j++){
        // durch Zeilen laufen von 0 -> 16
        for(int i=0; i<GRID_SIZE-PRODUCT_SIZE+1;i++){
            int localProduct = 1;
            for(int k=i; k<i+4; k++){
                localProduct *= grid[k][j];
            }
            if(localProduct > prod)
                prod = localProduct;
        }
    }
    return prod;
}

int largestProdInDiagRight(int ** grid){
    int prod = 1;
    // durch Zeilen laufen
    for(int i=0; i<GRID_SIZE-PRODUCT_SIZE+1; i++){
        // durch Spalte laufen von 0 -> 16
        for(int j=0; j<GRID_SIZE-PRODUCT_SIZE+1;j++){
            int localProduct = 1;
            for(int k=0; k<4; k++){
                localProduct *= grid[i+k][j+k];
            }
            if(localProduct > prod)
                prod = localProduct;
        }
    }
    return prod;
}

int largestProdInDiagLeft(int ** grid){
    int prod = 1;
    // durch Zeilen laufen
    for(int i=0; i<GRID_SIZE-PRODUCT_SIZE+1; i++){
        // durch Spalte laufen von 0 -> 16
        for(int j=PRODUCT_SIZE-1; j<GRID_SIZE;j++){
            int localProduct = 1;
            for(int k=0; k<4; k++){
                localProduct *= grid[i+k][j-k];
            }
            if(localProduct > prod)
                prod = localProduct;
        }
    }
    return prod;
}


int main(){
    
    

    // Speicher allokieren
    int ** grid = new int * [GRID_SIZE];
    for(int i=0; i<GRID_SIZE; i++)
        grid[i] = new int[GRID_SIZE];

    csvRead("input.csv", grid);

    if(DEBUG)
        for(unsigned int i=0; i<GRID_SIZE; i++){
            for(unsigned int j=0; j<GRID_SIZE; j++){
                cout << setw(2) << grid[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

    int globalProduct = 0;

    int rowMax = largestProdInRow(grid);
    if(rowMax > globalProduct)
        globalProduct = rowMax;

    int colMax = largestProdInCol(grid);
    if(colMax > globalProduct)
        globalProduct = colMax;

    int diagRightMax = largestProdInDiagRight(grid);
    if(diagRightMax > globalProduct)
        globalProduct = diagRightMax;

    int diagLeftMax = largestProdInDiagLeft(grid);
    if(diagLeftMax > globalProduct)
        globalProduct = diagLeftMax;

    cout << rowMax << endl;
    cout << colMax << endl;
    cout << diagRightMax << endl;
    cout << diagLeftMax << endl;


    // Speicher freigeben
    for(int i=0; i<GRID_SIZE; i++)
        delete [] grid[i];
    delete [] grid;

    return 0;
}