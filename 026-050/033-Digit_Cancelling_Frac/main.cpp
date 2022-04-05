#include <iostream>
#include <ctime>
#include <set>
#include <list>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

const bool  DEBUG   = false;
const int   SIZE    = 150000;

bool hasSharedDigit(int enumerator, int denominator){
    set<int> enumDigits;
    do{
        int digit = enumerator % 10;
        enumDigits.insert(digit);
        enumerator /= 10;

    }while(enumerator != 0);

    do{
        int digit = denominator % 10;
        if(enumDigits.count(digit) == 1){
            return true;
        }
        denominator /= 10;
    }while(denominator != 0);

    return false;
}

int getSharedDigits(int enumerator, int denominator){
    set<int> enumDigits;
    do{
        int digit = enumerator % 10;
        enumDigits.insert(digit);
        enumerator /= 10;

    }while(enumerator != 0);

    do{
        int digit = denominator % 10;
        if(enumDigits.count(digit) == 1){
            return digit;
        }
        denominator /= 10;
    }while(denominator != 0);

    return -1;
}

double getCutInverseFraction(int enumerator, int denominator, int cutableDigit){
    if(enumerator % 10 == cutableDigit){
        enumerator /= 10;
    }
    else{
        enumerator = enumerator % 10;
    }

    if(denominator % 10 == cutableDigit){
        denominator /= 10;
    }
    else{
        denominator = denominator % 10;
    }

    return denominator/(double) enumerator;
}

int main(){
    
    long long amountUniqueComputations = 0;
    clock_t start = clock();

    int possibleFractions = 0;
    int sumOfDenoms = 0;
    double prodOfCutDenom = 1;

    for(int enumerator = 11; enumerator < 100; enumerator++){
        for(int denominator = enumerator+1; denominator < 100; denominator++){

            

            // kill trivial solutions
            if(enumerator % 10 == 0)
                continue;
            if(denominator % 10 == 0)
                continue;

            

            // check if enum & denom share a digit
            if(!hasSharedDigit(enumerator, denominator))
                continue;


            // get cutable digits
            int cutableDigit = getSharedDigits(enumerator, denominator);
            
            // get inverseFraction to compare against cut inverseFraction
            double inverseFraction = denominator / (double) enumerator;
            double cutInverseFraction = getCutInverseFraction(enumerator, denominator, cutableDigit);

            if(inverseFraction != cutInverseFraction)
                continue;
            
            possibleFractions++;
            cout << setw(2) << enumerator << " / " << setw(2) << denominator << " {" << cutableDigit << "}";
            cout << " inverseFraction = " << inverseFraction; 
            cout << " cutInverseFraction = " << cutInverseFraction << endl;

            prodOfCutDenom *= cutInverseFraction;

        }
    }

    cout << "possible fractions = " << possibleFractions << endl << endl;
    cout << "product of cut denominators = " << prodOfCutDenom << endl << endl;

    clock_t end = clock();
    double runtime = (end - start)*1000 / CLOCKS_PER_SEC ;
    cout << "runtime: " << runtime << "ms" << endl;
    cout << "unique Computations: " << amountUniqueComputations << endl;
    return 0;
}