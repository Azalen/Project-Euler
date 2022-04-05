#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

void fillDigits(int num, vector<int> & v){
    do{

        int digit = num % 10;
        v.push_back(digit);
        num /= 10;

    }while(num != 0);
}

int main(){
    
    long long amountUniqueComputations = 0;
    clock_t start = clock();

    long long digitFactorialSum = 0;
    int fac[10] = {1,1,2,6,24,120,720,5040,40320,362880};

    vector<int> digits;

    // UPPER BOUND = 2.2m because 2.999.999 > 2! + 6*9! = 2.2m 
    for(int i = 11; i<2200000; i++){
        digits.clear();
        fillDigits(i,digits);
        long long digitFactorial = 0;
        for(int k = 0; k<digits.size(); k++){
            digitFactorial += fac[digits[k]];
        }
        if(i == digitFactorial){
            digitFactorialSum += i;
        }
    }

    cout << digitFactorialSum << endl;
    

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}