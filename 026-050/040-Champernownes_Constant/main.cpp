#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 1000000;

int main(){
    
    long long amountUniqueComputations = 0;
    clock_t start = clock();
    
    string champernowne = ".";
    for(int i = 1; i < SIZE; i++){
        champernowne += to_string(i);
    }
    long long res = 1;
    for(int i = 0; i < 7; i++){
        int digit = (champernowne[pow(10,i)]) -48;
        cout << digit << " ";
        res *= digit;
    }
    cout << endl << "d_n = " << res << endl;

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}