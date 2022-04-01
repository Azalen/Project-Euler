#include <iostream>
#include <ctime>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

int main(){
    
    clock_t start = clock();
    int amountUniqueComputations = 0;

    int totalCoinSum = 200;
    int r = 200;
    
    int coins[8] = {1,2,5,10,20,50,100,200};
    int anz = 0;

    for(int a = r; a >= 0; a = a - coins[7]){
        for(int b = a; b >= 0; b = b - coins[6]){
            for(int c = b; c >= 0; c = c - coins[5]){
                for(int d = c; d >= 0; d = d - coins[4]){
                    for(int e = d; e >= 0; e = e - coins[3]){
                        for(int f = e; f >= 0; f = f - coins[2]){
                            for(int g = f; g >= 0; g = g - coins[1]){
                                // no 8th for-loop cause 200x 1cent is only 1 solution
                                anz++;
                                amountUniqueComputations++;
                            }
                        }
                    }
                }
            }
        }
    }

    
    cout << "possibilities: " << anz << endl;

    clock_t end = clock();
    double runtime = (end - start)*1000000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ns" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}