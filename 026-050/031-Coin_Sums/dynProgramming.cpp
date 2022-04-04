#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){
    
    clock_t start = clock();
    int amountUniqueComputations = 0;

    int anz = 0;

    int amountCoints = 8;
    int totalValue = 200;

    int coinValue[amountCoints] = {1,2,5,10,20,50,100,200};

    int table[amountCoints][totalValue+1] = {0};

    // INIT TABLE
    for(int i = 0; i < amountCoints; i++){
        table[i][0] = 1;
        amountUniqueComputations++;
    }
    for(int j = 1; j < totalValue+1; j++){
        if(j % coinValue[0] == 0){
            table[0][j] = 1;
        }
        else{
            table[0][j] = 0;
        }
        amountUniqueComputations++;
    }


    // TEST PRINT
    if(DEBUG){
        cout << endl;
        for(int i = 0; i < amountCoints; i++){
            cout << setw(3) << coinValue[i] << " | ";
            for(int j = 0; j <= totalValue; j++){
                cout << setw(2) << table[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // DYNAMIC PROGRAMMING
    cout << endl;
    for(int i = 1; i < amountCoints; i++){
        for(int j = 1; j <= totalValue; j++){

            // if coinValue > currentAmount -> use value from above
            // because there is no 2nd part of the sum yet
            if(coinValue[i] > j){
                table[i][j] = table[i-1][j];
            }
            else{
                table[i][j] = table[i-1][j] + table[i][j-coinValue[i]];
            }
            amountUniqueComputations++;
        }
    }

    // FINAL PRINT
    if(DEBUG){
        cout << endl;
        for(int i = 0; i < amountCoints; i++){
            cout << setw(3) << coinValue[i] << " | ";
            for(int j = 0; j <= totalValue; j++){
                cout << setw(2) << table[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    anz = table[amountCoints-1][totalValue];
    cout << "possibilities: " << anz << endl;

    clock_t end = clock();
    double runtime = (end - start)*1000000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ns" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}